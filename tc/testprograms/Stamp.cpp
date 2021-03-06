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
#include <ctime>
using namespace std;
typedef vector<int> vi; 
typedef vector<string> vs; 
typedef pair<int, int> pii; 
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define INF 1<<29
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

ll dp[50][50];
string s;
int cost;

set<char> isUnit(string& s){
	set<char> S;
	REP(i,0,s.sz)S.insert(s[i]);
	S.erase('*');
	return S;	
}
bool issame(string s, string t){
	set<char> S=isUnit(s);
	set<char> T=isUnit(t);
	if(S.sz==0 || T.sz==0)return 1;
	if(S.sz>1 || T.sz>1)return 0;	
	vector<char> v(all(S));
	vector<char> u(all(T));
	return v[0]==u[0];
}

ll go(int I, int L){
	if(I>s.sz)return INF;
	if(I==s.sz)return 0;
	ll& ref=dp[I][L];
	if(ref!=-1)return ref;
	ref=INF;
	for(int i=max(I-L+1,0);i<=I;i++){
		string sub=s.substr(max(0,I-L),L);
		if(i==I)sub="";		
		string cad=s.substr(i,L);
		if(isUnit(cad).sz<=1 && issame(sub,cad)){
			//cout<<sub<<" eee "<<cad<<endl;			
			ref=min(ref,go(i+L,L)+cost);			
		}
	}	
	return ref;
}

class Stamp {
public:int getMinimumCost(string desiredColor, int stampCost, int pushCost) {	
		ll ans=INF;	
		cost=pushCost;

		fill(dp,-1);
		s=desiredColor;
		for(int l=1;l<=s.sz;l++){
			ans=min(ans,(stampCost*l)+go(0,l));			
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
bool KawigiEdit_RunTest(int testNum, string p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1 << "," << p2;
	cout << "]" << endl;
	Stamp *obj;
	int answer;
	obj = new Stamp();
	clock_t startTime = clock();
	answer = obj->getMinimumCost(p0, p1, p2);
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
	p0 = "RRGGBB";
	p1 = 1;
	p2 = 1;
	p3 = 5;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "R**GB*";
	p1 = 1;
	p2 = 1;
	p3 = 5;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "BRRB";
	p1 = 2;
	p2 = 7;
	p3 = 30;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "R*RR*GG";
	p1 = 10;
	p2 = 58;
	p3 = 204;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "*B**B**B*BB*G*BBB**B**B*";
	p1 = 5;
	p2 = 2;
	p3 = 33;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
	p1 = 7;
	p2 = 1;
	p3 = 30;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
