#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
double dis(int a, int b){
   return (a-b);
}
class TemperatureScales {
public:
   double convert( int f1, int b1, int f2, int b2, int t ) {
      return dis(t,f1)*dis(b2,f2)/dis(b1,f1)+f2;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int f1                    = 0;
			int b1                    = 100;
			int f2                    = 0;
			int b2                    = 100;
			int t                     = 28;
			double expected__         = 28.0;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int f1                    = 0;
			int b1                    = 100;
			int f2                    = 1;
			int b2                    = 101;
			int t                     = 28;
			double expected__         = 29.0;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int f1                    = -1000;
			int b1                    = -999;
			int f2                    = -1000;
			int b2                    = 1000;
			int t                     = 1000;
			double expected__         = 3999000.0;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int f1                    = -10;
			int b1                    = 0;
			int f2                    = 1;
			int b2                    = 2;
			int t                     = 17;
			double expected__         = 3.7;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int f1                    = 17;
			int b1                    = 98;
			int f2                    = -123;
			int b2                    = 12;
			int t                     = 22;
			double expected__         = -114.66666666666667;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int f1                    = ;
			int b1                    = ;
			int f2                    = ;
			int b2                    = ;
			int t                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int f1                    = ;
			int b1                    = ;
			int f2                    = ;
			int b2                    = ;
			int t                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int f1                    = ;
			int b1                    = ;
			int f2                    = ;
			int b2                    = ;
			int t                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TemperatureScales().convert(f1, b1, f2, b2, t);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
