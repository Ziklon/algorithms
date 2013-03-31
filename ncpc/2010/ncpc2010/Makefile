.PHONY: all ball %.show sampledata

TEXSOURCE=$(wildcard *.tex) \
       $(wildcard */*.tex)

PROBLEMS=succession  #allergy soda money rain escape gokigen beacons playfair permutations flight

#AUTHORS=pa tab ng og jm mg ab sn mi jmv
AUTHORS=mi jmv mg ab jm pa
EXT=java cc cpp c

all: ncpc2010problems.pdf ncpc2010slides.pdf # ncpc2010solutions.pdf 
ball: ncpc2010ball.tar.gz ncpc2010sampledata.tar.gz ncpc2010data.tar.gz ncpc2010solutions.tar.gz
show: ncpc2010problems.show
shows: ncpc2010solutions.show

ncpc2010data.tar:
	if [ -e $@ ]; then \
		rm -R $@; \
	fi; \
	for P in ${PROBLEMS}; do \
		tar rvf $@ $${P}/data/*.in $${P}/data/*.ans; \
	done

ncpc2010sampledata.tar:
	if [ -e $@ ]; then \
		rm -R $@; \
	fi; \
	for P in ${PROBLEMS}; do \
		tar rvf $@ $${P}/*.inex $${P}/*.outex; \
	done

ncpc2010ball.tar:
	if [ -e $@ ]; then \
		rm -R $@; \
	fi; \
	for P in ${PROBLEMS}; do \
		tar rvf $@ $${P}/data/*.in $${P}/data/*.ans; \
		tar rvf $@ $${P}/$${P}.*.inex $${P}/$${P}.*.outex; \
		for A in ${AUTHORS}; do \
			for E in ${EXT}; do \
				export N=$${P}/$${P}_$${A}.$${E}; \
				if [ -f $${N} ]; then \
					tar rvf $@ $${N}; \
				fi \
			done; \
		done; \
	done; \
 	tar rvf $@ ncpc2010problems.pdf; \
 	tar rvf $@ ncpc2010slides.pdf; \



ncpc2010solutions.tar:
	if [ -e $@ ]; then \
		rm -R $@; \
	fi; \
	for P in ${PROBLEMS}; do \
		for A in ${AUTHORS}; do \
			for E in ${EXT}; do \
				export N=$${P}/$${P}_$${A}.$${E}; \
				if [ -f $${N} ]; then \
					tar rvf $@ $${N}; \
				fi \
			done; \
		done; \
	done; \


# 	tar rvf $@ code/code_ng_st.cpp;
# 	tar --delete -vf $@ triangle/triangle_ng.cpp;

#ncpc2010sampledata.tar:
#	if [ -e $@ ]; then \
#		rm -R $@; \
#	fi; \
#	mkdir $@; \
#	for P in ${PROBLEMS}; do \
#		cp $${P}/$${P}.*.inex $${P}/$${P}.*.outex $@; \
#	done; \
#	cd $@; \
#	tar czvf ncpc2010sampledata.tar.gz *.inex *.outex; \
#	zip ncpc2010sampledata.zip *.inex *.outex; 

%.pdf:  %.tex $(TEXSOURCE)
	#echo $(TEXSOURCE)
	#rubber -d $<
	pdflatex $<
	pdflatex $<

%.show: %.pdf
	xpdf -z page $<

%.tar.gz: %.tar
	gzip -f $<

clean:
	@echo Cleaning.
	@ -$(RM) *.log *.aux *.blg *.bbl *.toc *~ *.ps
	@ -$(RM) ncpc2010problems.pdf ncpc2010solutions.pdf ncpc2010slides.pdf
	@ -$(RM) ncpc2010ball.tar.gz ncpc2010ball.tar
	@echo done
