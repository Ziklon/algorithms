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

class ATaleOfThreeCities {
public:
   double connect( vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy ) {
      double dev=1<<30;
      double ab=dev,bc=dev,ac=dev;
      for(int i=0;i<ax.sz;i++)
         for(int j=0;j<bx.sz;j++)
            ab=min(hypot(ax[i]-bx[j],ay[i]-by[j]),ab);
      for(int i=0;i<cx.sz;i++)
         for(int j=0;j<bx.sz;j++)
            bc=min(hypot(cx[i]-bx[j],cy[i]-by[j]),bc);

      for(int i=0;i<cx.sz;i++)
         for(int j=0;j<ax.sz;j++)
            ac=min(hypot(cx[i]-ax[j],cy[i]-ay[j]),ac);
      dev=ab+ac+bc - max(ab,max(ac,bc));
      return dev;
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
			int ax[]                  = {0,0,0};
			int ay[]                  = {0,1,2};
			int bx[]                  = {2,3};
			int by[]                  = {1,1};
			int cx[]                  = {1,5};
			int cy[]                  = {3,28};
			double expected__         = 3.414213562373095;

			clock_t start__           = clock();
			double received__         = ATaleOfThreeCities().connect(vector <int>(ax, ax + (sizeof ax / sizeof ax[0])), vector <int>(ay, ay + (sizeof ay / sizeof ay[0])), vector <int>(bx, bx + (sizeof bx / sizeof bx[0])), vector <int>(by, by + (sizeof by / sizeof by[0])), vector <int>(cx, cx + (sizeof cx / sizeof cx[0])), vector <int>(cy, cy + (sizeof cy / sizeof cy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int ax[]                  = {-2,-1,0,1,2};
			int ay[]                  = {0,0,0,0,0};
			int bx[]                  = {-2,-1,0,1,2};
			int by[]                  = {1,1,1,1,1};
			int cx[]                  = {-2,-1,0,1,2};
			int cy[]                  = {2,2,2,2,2};
			double expected__         = 2.0;

			clock_t start__           = clock();
			double received__         = ATaleOfThreeCities().connect(vector <int>(ax, ax + (sizeof ax / sizeof ax[0])), vector <int>(ay, ay + (sizeof ay / sizeof ay[0])), vector <int>(bx, bx + (sizeof bx / sizeof bx[0])), vector <int>(by, by + (sizeof by / sizeof by[0])), vector <int>(cx, cx + (sizeof cx / sizeof cx[0])), vector <int>(cy, cy + (sizeof cy / sizeof cy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int ax[]                  = {4,5,11,21,8,10,3,9,5,6};
			int ay[]                  = {12,8,9,12,2,3,5,7,10,13};
			int bx[]                  = {34,35,36,41,32,39,41,37,39,50};
			int by[]                  = {51,33,41,45,48,22,33,51,41,40};
			int cx[]                  = {86,75,78,81,89,77,83,88,99,77};
			int cy[]                  = {10,20,30,40,50,60,70,80,90,100};
			double expected__         = 50.323397776611024;

			clock_t start__           = clock();
			double received__         = ATaleOfThreeCities().connect(vector <int>(ax, ax + (sizeof ax / sizeof ax[0])), vector <int>(ay, ay + (sizeof ay / sizeof ay[0])), vector <int>(bx, bx + (sizeof bx / sizeof bx[0])), vector <int>(by, by + (sizeof by / sizeof by[0])), vector <int>(cx, cx + (sizeof cx / sizeof cx[0])), vector <int>(cy, cy + (sizeof cy / sizeof cy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int ax[]                  = ;
			int ay[]                  = ;
			int bx[]                  = ;
			int by[]                  = ;
			int cx[]                  = ;
			int cy[]                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ATaleOfThreeCities().connect(vector <int>(ax, ax + (sizeof ax / sizeof ax[0])), vector <int>(ay, ay + (sizeof ay / sizeof ay[0])), vector <int>(bx, bx + (sizeof bx / sizeof bx[0])), vector <int>(by, by + (sizeof by / sizeof by[0])), vector <int>(cx, cx + (sizeof cx / sizeof cx[0])), vector <int>(cy, cy + (sizeof cy / sizeof cy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int ax[]                  = ;
			int ay[]                  = ;
			int bx[]                  = ;
			int by[]                  = ;
			int cx[]                  = ;
			int cy[]                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ATaleOfThreeCities().connect(vector <int>(ax, ax + (sizeof ax / sizeof ax[0])), vector <int>(ay, ay + (sizeof ay / sizeof ay[0])), vector <int>(bx, bx + (sizeof bx / sizeof bx[0])), vector <int>(by, by + (sizeof by / sizeof by[0])), vector <int>(cx, cx + (sizeof cx / sizeof cx[0])), vector <int>(cy, cy + (sizeof cy / sizeof cy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int ax[]                  = ;
			int ay[]                  = ;
			int bx[]                  = ;
			int by[]                  = ;
			int cx[]                  = ;
			int cy[]                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = ATaleOfThreeCities().connect(vector <int>(ax, ax + (sizeof ax / sizeof ax[0])), vector <int>(ay, ay + (sizeof ay / sizeof ay[0])), vector <int>(bx, bx + (sizeof bx / sizeof bx[0])), vector <int>(by, by + (sizeof by / sizeof by[0])), vector <int>(cx, cx + (sizeof cx / sizeof cx[0])), vector <int>(cy, cy + (sizeof cy / sizeof cy[0])));
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
