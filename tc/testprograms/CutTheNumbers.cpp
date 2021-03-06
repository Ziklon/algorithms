#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
using namespace std;
int dp[1<<16], M, N;
vector<string> board;
int g(int mask) {
	if(__builtin_popcount(mask) == M*N) return 0;
	int& ref = dp[mask];
	if(ref != -1) return ref;
	ref = 0;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			int pos = N * i + j;
			if((mask & (1<<pos)) == 0) {
				int num = 0;
				int newmask = 0;
				for(int k = j; k < N; k++) {
					int npos = N * i + k;
					if((mask & (1<<npos)) != 0) break;
					num = (num * 10) + board[i][k] - '0';
					newmask|=1<<npos;
					ref = max(ref, num + g(mask | newmask));
				}
				num = 0;
				newmask = 0;
				for(int k = i; k < M; k++) {
					int npos = N * k + j;
					if((mask & (1<<npos)) != 0) break;
					num = (num * 10) + board[k][j] - '0';
					newmask |= 1<<npos;
					ref = max(ref, num + g(mask | newmask));
					
				}
			}
		}
	}
	return ref;
}
class CutTheNumbers {
public:int maximumSum(vector <string> __board) {	
		int ans;
		M = __board.size();
		N = __board[0].length();
		board = __board;
		memset(dp, -1, sizeof dp);
		ans = g(0);
		return ans;		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	CutTheNumbers *obj;
	int answer;
	obj = new CutTheNumbers();
	clock_t startTime = clock();
	answer = obj->maximumSum(p0);
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"123","312"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 435;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"99","11"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 182;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"001","010","111","100"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1131;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"8"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8;
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
