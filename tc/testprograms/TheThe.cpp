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

class TheThe {
public:
   int check( vector <string> lines ) {
      int dev=-1;
      string cur="",aux;
      for(int i=0;i<lines.sz && dev==-1;i++){
         stringstream ss(lines[i]);
         ss>>aux;
         if(aux==cur)dev =i-1;
         while(ss>>aux);
         cur=aux;
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

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
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
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string lines[]            = { "It was the best of times it was",
  "the worst of times it was the",
  "the age of wisdom it was the age",
  "of foolishness it was the epoch",
  "epoch of belief it was the epoch",
  "of incredulity" };
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string lines[]            = { "I like you",
  "You like me",
  "Lets have dinner" };
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string lines[]            = { "Sometimes I call my father Pops",
  "PopsEdit is a feature rich editor",
  "Just once I would like to beat SnapDragon",
  "Dragon stew is tasty but the ingredients",
  "are difficult to come by" };
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string lines[]            = { "A line might contain a",
  "single",
  "word" };
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string lines[]            = { "I know that",
  "that kind of food",
  "is bad for me but",
  "I like it anyway" };
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheThe().check(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
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
