import sys
import os
import logging
import glob
from optparse import OptionParser

SUFFIXES = {
		'.c' : 'C',
		'.cc' : 'C++',
		'.cpp' : 'C++',
		'.java' : 'Java',
		}

COMPILE = {
		'C' : 'gcc -O2 -Wall -lm -o "%(exec)s" "%(file)s"',
		'C++' : 'g++ -I../include -O2 -Wall -o "%(exec)s" "%(file)s"',
		'Java' : 'javac -O "%(file)s"'
		}

RUN = {
		'C' : ['./%(exec)s'],
		'C++' : ['./%(exec)s'],
		'Java' : ['java', '-client', '-Xmx128m', '-Xss5m', '%(exec)s'],
		}

ANSSUFFIXES = {
		'.in' : '.ans',
		'.inex' : '.outex',
		}

def find_dirs(options):
	ret = []
	for dir in [x for x in os.listdir('.') if os.path.isdir(x)]:
		if looks_like_problem(dir, options):
			ret.append(dir)
	return ret

def get_solutions(dir, options):
	if options.solutions:
		return [os.path.basename(f.strip()) for f in open(options.solutions).readlines() if f.startswith(dir + os.path.sep)]
	return [f for f in os.listdir(dir)
	                if os.path.splitext(f)[1] in SUFFIXES
	                and f.find('_') != -1
	                and f.find('_gen') == -1
	                and f.find('_judge') == -1
	                and f.find('_err_') == -1]

def get_corrector(dir, options):
	if options.corrector != 'diff':
		return options.corrector
	corrs = [f for f in os.listdir(dir)
	                if os.path.splitext(f)[1] in SUFFIXES
	                and f.find('_judge') != -1]
	if len(corrs)>=1:
		return corrs[0]
	else:
		return 'diff'

def get_datafiles(dir):
	ret = [ os.path.basename(f) for f in glob.glob(os.path.join(dir, '*.inex')) ]
	ret += [ os.path.basename(f) for f in glob.glob(os.path.join(dir, '*.in')) ]
	datadir = os.path.join(dir, 'data')
	if os.path.isdir(datadir):
		ret += [os.path.join('data', os.path.basename(f)) for f in glob.glob(os.path.join(datadir, '*.in'))] 
	ret.sort()
	return ret

def _setfd(fd, filename, flag):
	tmpfd = os.open(filename, flag)
	os.dup2(tmpfd, fd)
	os.close(tmpfd)

def run_wait(cmd, args, infile="/dev/null", outfile="/dev/null", errfile="/dev/null"):
#	logging.debug('run_wait(%s, %s, infile=%s, outfile=%s, errfile=%s)', cmd, args, infile, outfile, errfile)
	pid = os.fork()
	if pid == 0: # child
		try:
			_setfd(0, infile, os.O_RDONLY)
			_setfd(1, outfile, os.O_WRONLY | os.O_CREAT | os.O_TRUNC)
			_setfd(2, errfile, os.O_WRONLY | os.O_CREAT | os.O_TRUNC)
			os.execvp(cmd, args)
		except:
			os.kill(os.getpid(), signal.SIGTERM)
		#Unreachable
		os.kill(os.getpid(), signal.SIGTERM)
	else:
		(pid, status, rusage) = os.wait4(pid, 0)
		return status, rusage.ru_utime + rusage.ru_stime

def get_exec_name(source):
	return os.path.splitext(source)[0]

def run_solution(solution, file, corrector, options):
	subs = { 'exec' : get_exec_name(solution) }
	args = [arg % subs for arg in RUN[SUFFIXES[os.path.splitext(solution)[1]]]]

	outfile = os.path.splitext(file)[0] + '.out'
	ansfile = os.path.splitext(file)[0] + ANSSUFFIXES[os.path.splitext(file)[1]]

	status, runtime = run_wait(args[0], args, infile=file, outfile=outfile)
	if not os.WIFEXITED(status) or os.WEXITSTATUS(status) != 0:
		logging.error('Judge solution %s running on input %s did not exit properly, status: %d', solution, file, status)
		os.unlink(outfile)
		return runtime

	if not os.path.exists(ansfile):
		logging.info('Copying output of %s as answer for input %s', solution, file)
		open(ansfile, 'w').write(open(outfile, 'r').read())
	
	if corrector != 'diff':
		status = os.system('"%s" "%s" "%s" "%s" < "%s" > /dev/null 2> /dev/null' % ("./" + get_exec_name(corrector), file, ansfile, "tmp_judge_tmp", outfile))
# 		os.unlink("tmp_judge_tmp")
	else:
		status = os.system('"%s" "%s" "%s" > /dev/null 2> /dev/null' % (corrector, outfile, ansfile))
	if not os.WIFEXITED(status) or os.WEXITSTATUS(status) != 0:
		logging.error('Judge solution %s running on input %s did not answer correctly', solution, file)
		os.unlink(outfile)
		return runtime
	os.unlink(outfile)
	return runtime

def looks_like_problem(dir, options):
	return get_solutions(dir, options) and get_datafiles(dir)

def compile(solution):
	compiler = COMPILE[SUFFIXES[os.path.splitext(solution)[1]]]
	args = { 'file' : solution, 'exec' : get_exec_name(solution) }
	logging.info('Compiling %s', solution)
#	logging.debug('system(%s)', compiler % args)
	status = os.system(compiler % args)
	if not os.WIFEXITED(status) or os.WEXITSTATUS(status) != 0:
		logging.error('Compiler failed (status %d) when compiling %s', status, solution)
		return False
	return True

def print_limit(times, options):
	maxtime = max( [ (max(r[0]), r[1]) for r in times] )
	maxtottime = max( [ (sum(r[0]), r[1]) for r in times] )

	limit = int(max(options.mintime, options.speedmargin * maxtime[0]) + .5)
	for r in times:
		logging.info('Judge %s had worst case time %f, total time %f', r[1], max(r[0]), sum(r[0]))
	print 'Suggested limit: %d, slowest judge: %f (%s), worst total time: %f (%s)\n\n' % (limit, maxtime[0], maxtime[1], maxtottime[0], maxtottime[1])

def do_problem(dir, options):
	if not looks_like_problem(dir, options):
		logging.warning("Directory \"%s\" does not look like it contains a problem" , dir)
		return

	print dir

	files = get_datafiles(dir)
	solutions = get_solutions(dir, options)
	corrector = get_corrector(dir, options)

	logging.info("Found %d judge solutions and %d input files for problem %s", len(solutions), len(files), dir)
	logging.info("Using %s as corrector", corrector)

	os.chdir(dir)
	if (corrector != 'diff'):
		compile(corrector)
	times = []
	for solution in solutions:
		if compile(solution):
			logging.info('Running %s', solution)
			curr_times = []
			for file in files:
				curr_time = 0
				for i in xrange(options.count):
					curr_time = max(curr_time, run_solution(solution, file, corrector, options))
				logging.debug('Time for %s on %s was %lf', solution, file, curr_time)
				curr_times.append(curr_time)
			times.append((curr_times, solution))
	print_limit(times, options)
	os.chdir('..')

if __name__ == '__main__':
	parser = OptionParser(usage="usage: %prog [options] [problems]")
	parser.add_option("-m", "--mintime", dest="mintime", help="minimum time limit", default=2, type="int")
	parser.add_option("-s", "--speedmargin", dest="speedmargin", help="factor between slowest judge solution and suggested time limit", default=3, type="float")
	parser.add_option("-n", "--count", dest="count", help="number of times to run each solution", default=3, type="int")
	parser.add_option("-l", "--log-level", dest="loglevel", help="set log level (debug, info, warning, error, critical)", default="info")
	parser.add_option("-c", "--corrector", dest="corrector", help="special corrector binary", default="diff")
	parser.add_option("-S", "--solutions", dest="solutions", help="File listing source files which are valid solutions")
	(options, args) = parser.parse_args()

	logging.basicConfig(level=eval("logging." + options.loglevel.upper()))

	if args:
		dirs = args
	else:
		dirs = find_dirs(options)

	for dir in dirs:
		do_problem(dir, options)
