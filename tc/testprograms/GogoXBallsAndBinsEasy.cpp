#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef pair<int, int> pii; 
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)


class GogoXBallsAndBinsEasy {
public:int solve(vector <int> T) {	
		vector<int> v(all(T));
		reverse(all(v));
		int peki=0;
		REP(i,0,v.sz)peki+=abs(v[i]-T[i]);
		return peki/2;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	GogoXBallsAndBinsEasy *obj;
	int answer;
	obj = new GogoXBallsAndBinsEasy();
	clock_t startTime = clock();
	answer = obj->solve(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {0,2,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,6,7,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,1,2,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 11;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,2,3,4,5,6,7,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 16;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
