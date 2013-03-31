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
int P=10;

int fastExp(int n, int m){
   if(m==0)
         return 1;
   int dev=fastExp(n,m/2)%P;
   dev=(dev*dev)%P;
   if(m&1)
      dev=(dev*n)%P;
   return dev;
}
class Generators {
public:
   vector <int> find( int p ) {

       vector<int>v,dev;
       P=p;
       for(int i=2;i<p;i++)v.pb(i);
       for(int i=2;i<p;i++){
           vector<int>aux;
            for(int j=1;j<p-1;j++)
               aux.pb(fastExp(i,j));
           sort(all(aux));
           if(aux==v)
               dev.pb(i);
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
			int p                     = 3;
			int expected__[]          = {2 };

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int p                     = 5;
			int expected__[]          = {2, 3 };

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int p                     = 13;
			int expected__[]          = {2, 6, 7, 11 };

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int p                     = 19;
			int expected__[]          = {2, 3, 10, 13, 14, 15 };

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int p                     = 337;
			int expected__[]          = {10, 15, 19, 20, 22, 23, 29, 31, 33, 34, 44, 45, 46, 51, 53, 60, 61, 67, 68, 70, 71, 73, 80, 83, 87, 89, 90, 93, 99, 101, 106, 109, 114, 116, 118, 120, 124, 130, 132, 134, 139, 143, 151, 152, 154, 160, 161, 166, 171, 176, 177, 183, 185, 186, 194, 198, 203, 205, 207, 213, 217, 219, 221, 223, 228, 231, 236, 238, 244, 247, 248, 250, 254, 257, 264, 266, 267, 269, 270, 276, 277, 284, 286, 291, 292, 293, 303, 304, 306, 308, 314, 315, 317, 318, 322, 327 };

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int p                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int p                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int p                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = Generators().find(p);
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
