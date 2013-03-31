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

class DerivativeSequence {
public:
   vector <int> derSeq( vector <int> a, int n ) {
        if(n==0)return a;
        vector<int> dev;
        for(int i=0;i+1<a.sz;i++)
            dev.pb(a[i+1]-a[i]);
        return derSeq(dev,n-1);
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

	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) {
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
			int a[]                   = {5,6,3,9,-1};
			int n                     = 1;
			int expected__[]          = {1, -3, 6, -10 };

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {5,6,3,9,-1};
			int n                     = 2;
			int expected__[]          = {-4, 9, -16 };

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {5,6,3,9,-1};
			int n                     = 4;
			int expected__[]          = {-38 };

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {4,4,4,4,4,4,4,4};
			int n                     = 3;
			int expected__[]          = {0, 0, 0, 0, 0 };

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {-100,100};
			int n                     = 0;
			int expected__[]          = {-100, 100 };

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int n                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DerivativeSequence().derSeq(vector <int>(a, a + (sizeof a / sizeof a[0])), n);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
