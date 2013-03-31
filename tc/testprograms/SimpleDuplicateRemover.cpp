#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

vector<bool> vis(1005,0);
class SimpleDuplicateRemover {
public:
   vector <int> process( vector <int> sequence ) {
		vector<int> ans;
		int N=sequence.size();
		for(int i=N-1;i>=0;i--){
			if(vis[sequence[i]])continue;			
			vis[sequence[i]]=1;
			ans.insert(ans.begin(),sequence[i]);
		}
		return ans;
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

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int sequence[]            = {1,5,5,1,6,1};
			int expected__[]          = {5, 6, 1 };

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int sequence[]            = {2,4,2,4,4};
			int expected__[]          = {2, 4 };

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int sequence[]            = {6,6,6,6,6,6};
			int expected__[]          = {6 };

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int sequence[]            = {1,2,3,4,2,2,3};
			int expected__[]          = {1, 4, 2, 3 };

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int sequence[]            = {100,100,100,99,99,99,100,100,100};
			int expected__[]          = {99, 100 };

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sequence[]            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int sequence[]            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int sequence[]            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = SimpleDuplicateRemover().process(vector <int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
