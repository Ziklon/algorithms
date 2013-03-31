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
long long dp[31][10];
long long g(int nd, int digit) {
	if(nd == 1) return 1;
	long long& ref = dp[nd][digit];
	if(ref != -1) return ref;
	ref = 0;
	if(digit == 0) ref += g(nd - 1, 7);
	if(digit == 1) ref += g(nd - 1, 2) + g(nd - 1, 4);
	if(digit == 2) ref += g(nd - 1, 1) + g(nd - 1, 3) + g(nd - 1, 5);
	if(digit == 3) ref += g(nd - 1, 2) + g(nd - 1, 6);
	if(digit == 4) ref += g(nd - 1, 7) + g(nd - 1, 1) + g(nd - 1, 5);
	if(digit == 5) ref += g(nd - 1, 4) + g(nd - 1, 2) + g(nd - 1, 6) + g(nd - 1, 8);
	if(digit == 6) ref += g(nd - 1, 3) + g(nd - 1, 5) + g(nd - 1, 9);
	if(digit == 7) ref += g(nd - 1, 4) + g(nd - 1, 8) + g(nd - 1, 0);
	if(digit == 8) ref += g(nd - 1, 7) + g(nd - 1, 5) + g(nd - 1, 9);
	if(digit == 9) ref += g(nd - 1, 8) + g(nd - 1, 6);
	return ref;
}
class UnsealTheSafe {
public:long long countPasswords(int N) {	
		long long ans=0;
		memset(dp, -1, sizeof dp);
		
		for(int i = 0; i < 10; i++) {
			ans += g(N, i);
		}
		return ans;		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	UnsealTheSafe *obj;
	long long answer;
	obj = new UnsealTheSafe();
	clock_t startTime = clock();
	answer = obj->countPasswords(p0);
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
	
	int p0;
	long long p1;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 26ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 74ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 25;
	p1 = 768478331222ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
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
