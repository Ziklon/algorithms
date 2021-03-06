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

#define all(v) (v).begin(),(v).end()

#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
set<string> S;
string cur,aux;
int Lim;
void go(string s,int p){
	if(p>=Lim){
		aux=s;
		reverse(all(aux));
		s=s+aux;
		S.insert(s);

		return;
	}
	int x=-1;
	REP(i,p,Lim){
		if(cur[i]=='?'){
			x=i;
			break;
		}
	}
	if(x!=-1){

		go(s+cur.substr(p,x-p)+'x',x+1);
		go(s+cur.substr(p,x-p)+'o',x+1);
	}else{
		go(s+cur.substr(p,Lim-p),Lim);
	}	
}

bool isPal(string s){
	string cp=s;
	reverse(all(cp));
	return cp==s;
}
class MinCostPalindrome {
public:int getMinimum(string s, int oCost, int xCost) {	
		cur=s;
		S.clear();
		Lim=s.sz/2;
		go("",0);
		int peki=1<<29;

		foreach(S,it){
			cur=*it;
			bool ok=1;

			REP(i,0,s.sz)if(s[i]!='?' && s[i]!=cur[i])ok=0;

			if(ok && isPal(cur)){

				int cost=0;
				REP(i,0,s.sz){
					if(s[i]=='?')
						if(cur[i]=='o')
							cost+=oCost;
						else 
							cost+=xCost;

				}
				peki=min(peki,cost);
			}
		}
		if(peki<(1<<29))return peki;
		return -1;		
	}

};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
	cout << "]" << endl;
	MinCostPalindrome *obj;
	int answer;
	obj = new MinCostPalindrome();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	string p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = "oxo?xox?";
	p1 = 3;
	p2 = 5;
	p3 = 8;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "x?" "?x";
	p1 = 9;
	p2 = 4;
	p3 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ooooxxxx";
	p1 = 12;
	p2 = 34;
	p3 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "oxoxooxxxxooxoxo";
	p1 = 7;
	p2 = 4;
	p3 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "?o";
	p1 = 6;
	p2 = 2;
	p3 = 6;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?" "?";
	p1 = 50;
	p2 = 49;
	p3 = 980;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "o?" "?oxxo?xoox?ox?" "?x?" "?";
	p1 = 3;
	p2 = 10;
	p3 = 38;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
//With unused code cleaner (beta) by ahmed_aly
