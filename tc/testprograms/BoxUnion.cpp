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
vector<int> split(string s){
   vector<int> dev;
   int n;
   istringstream is(s);
   while(is>>n)dev.push_back(n);
   return dev;
}
string interset(string r, string s){
   vector<int> a=split(r);
   vector<int> b=split(s);
   int x1=max(a[0],b[0]);
   int y1=max(a[1],b[1]);
   int x2=min(a[2],b[2]);
   int y2=min(a[3],b[3]);
   if(x1>=x2|| y1>=y2)return "0 0 0 0";
   stringstream ss;
   ss<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
   return ss.str();
}
int square(string s){
   vector<int>v=split(s);
   return abs(v[0]-v[2])*abs(v[1]-v[3]);
}
class BoxUnion {
public:
   int area( vector <string> rec) {
      int dev=0;
      if(rec.sz==1)return square(rec[0]);
      if(rec.sz==2)return square(rec[0])+square(rec[1])-square(interset(rec[0],rec[1]));
      dev=square(rec[0])+square(rec[1])+square(rec[2])-square(interset(rec[0],rec[1]))-square(interset(rec[2],rec[1]));
      dev=dev-square(interset(rec[2],rec[0])) + square(interset(rec[0],interset(rec[1],rec[2])));

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
			string rectangles[]       = { "200 300 203 304" };
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string rectangles[]       = { "0 0 10 10",
  "20 20 30 30" };
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string rectangles[]       = { "0 500 20000 501",
  "500 0 501 20000" };
			int expected__            = 39999;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string rectangles[]       = { "4 6 18 24",
  "7 2 12 19",
  "0 0 100 100" };
			int expected__            = 10000;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string rectangles[]       = { "1 3 5 6",
  "3 1 7 5",
  "4 4 9 7" };
			int expected__            = 35;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string rectangles[]       = { "0 0 20000 20000",
  "0 0 20000 20000",
  "0 0 20000 20000" };
			int expected__            = 400000000;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string rectangles[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string rectangles[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string rectangles[]       = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BoxUnion().area(vector <string>(rectangles, rectangles + (sizeof rectangles / sizeof rectangles[0])));
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
