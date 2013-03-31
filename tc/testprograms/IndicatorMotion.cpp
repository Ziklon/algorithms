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

class IndicatorMotion {
public:
   string getMotion( string program, char startState ) {
      map<char,char>L;
      L['|']='\\';
      L['\\']='-';
      L['-']='/';
      L['/']='|';
      map<char,char>R;
      R['|']='/';
      R['\\']='|';
      R['-']='\\';
      R['/']='-';
      map<char,char>F;
      F['\\']='/';
      F['/']='\\';
      F['-']='|';
      F['|']='-';
      string dev=string(1,startState);
      int cnt=0;
      char cur;
      istringstream is(program);
      while(is>>cur>>cnt){
         for(int i=0;i<cnt;i++){
            switch(cur){
               case 'R':
                     startState=R[startState];
                     break;
               case 'L':
                     startState=L[startState];
                     break;
               case 'F':
                     startState=F[startState];
                     break;
            }
            dev+=string(1,startState);
         }
      }
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

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string program            = "F03L02R03S02F04";
			char startState           = '-';
			string expected__         = "-|-|\\-\\|///\\/\\/";

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string program            = "F10R01F10";
			char startState           = '/';
			string expected__         = "/\\/\\/\\/\\/\\/-|-|-|-|-|-";

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string program            = "";
			char startState           = '/';
			string expected__         = "/";

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string program            = "F00R00L00S00";
			char startState           = '\\';
			string expected__         = "\\";

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string program            = ;
			char startState           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string program            = ;
			char startState           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string program            = ;
			char startState           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = IndicatorMotion().getMotion(program, startState);
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
