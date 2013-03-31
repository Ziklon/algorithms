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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

class DocumentSearch {
public:
   int nonIntersecting( vector <string> doc, string search ) {
				int dev=0;
				int n=search.sz;
				string docs=accumulate(all(doc),string());
				for(int i=0;i+n<=docs.sz;i++){
						string s=docs.substr(i,n);
						if(s==search){
								dev++;
								i+=n-1;
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
			string doc[]              = {"ababababa"};
			string search             = "ababa";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string doc[]              = {"ababababa"};
			string search             = "aba";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string doc[]              = {"abcdefghijklmnop",
 "qrstuvwxyz"};
			string search             = "pqrs";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string doc[]              = {"aaa", "aa", "a", "a"};
			string search             = "aa";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string doc[]              = ;
			string search             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string doc[]              = ;
			string search             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string doc[]              = ;
			string search             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
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
