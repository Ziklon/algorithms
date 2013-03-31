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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int pos[60];

class NetworkXMessageRecovery {
public:string recover(vector <string> ms) {	
		int i,j,k,N;
		N=ms.sz;
		REP(i,0,N)pos[i]=0;
		string ans="";	
		while(1){
			bool finish=1;
			REP(i,0,N)if(pos[i]<ms[i].sz)finish=0;
			if(finish)break;
			REP(i,0,52){
				char cur=(i>25)?'a'+(i-26):'A'+i;
				bool flag=0;
				REP(j,0,N)if(pos[j]<ms[j].sz && ms[j][pos[j]]==cur)flag=1;
				REP(j,0,N)REP(k,pos[j]+1,ms[j].sz)if(ms[j][k]==cur)flag=0;
				if(flag){
					ans+=cur;
					REP(j,0,N)if(pos[j]<ms[j].sz && ms[j][pos[j]]==cur)pos[j]++;
					break;
				}
			}
			
		}
		return ans;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	NetworkXMessageRecovery *obj;
	string answer;
	obj = new NetworkXMessageRecovery();
	clock_t startTime = clock();
	answer = obj->recover(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"acd","bce"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "abcde";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"ed","dc","cb","ba"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "edcba";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"Fox","Ciel","FoxCiel"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "FoxCiel";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"a","A"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Aa";
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
