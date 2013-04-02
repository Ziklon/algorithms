#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define MOD 1234567891
typedef long long ll;
int color(char  c){
	if(c=='H' || c=='D')return 1;
	return 2;
}
vector<pair<int,char> >v;
int n;
ll dp[16][1<<16];
ll go(int index, int mask){
	if(__builtin_popcount(mask)==n)return 1;
	ll& ref=dp[index][mask];
	if(ref!=-1)return ref;
	ref=0;
	REP(i,n){
		if((mask&(1<<i))==0 && (v[i].first==v[index].first || 
					v[i].second==v[index].second)){
			ref=(ref+go(i,mask|(1<<i)))%MOD;	
		}
	}
	return ref;
}

struct TheCardLineDivTwo {
   int count( vector <string> cards ) {
        int ans=0;
		n=cards.size();
		REP(i,n)v.push_back(make_pair(color(cards[i][1]),cards[i][0]));
		memset(dp,-1,sizeof dp);
		REP(i,n)ans=(ans+go(i,1<<i))%MOD;	
		return ans;

   }
};


// Powered by FileEdit
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
	TheCardLineDivTwo *obj;
	int answer;
	obj = new TheCardLineDivTwo();
	clock_t startTime = clock();
	answer = obj->count(p0);
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
	string t0[] = {"KH","QD","KC"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"JS","JC","JD","JH"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 24;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"2S","3C","4C","5S","6C","7S","8S","9H"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"KD","KC","AD","7C","AH","9C","4H","4S","AS"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2416;
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
// Powered by TesterDream 1.2.4 by fushar (December 19 2012)
// Powered by CodeProcessor
