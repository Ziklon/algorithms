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

#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

#define fill(x,i) memset(x,i,sizeof(x))
struct Node{
	int x,y,c;
	Node(){}
	Node(int p,int q, int r){
		x=p;y=q;c=r;
	}
	bool operator < (const Node& p)const{
		return y>p.y;
	}
};
int g,v;
int dp[55];
int C[55];
Node P[55];
int N;

int go(int index){
	int& ref=dp[index];
	if(ref!=-1)return ref;	
	ref=P[index].c;
	REP(i,index+1,N){
		long long vx=P[index].x-P[i].x;
		long long vy=P[index].y-P[i].y;		
		if(2*vy*v*v>=vx*vx*g){
			ref=max(ref,P[index].c+go(i));
		}

	}	
	return ref;
}

class PlatformJumper {
public:int maxCoins(vector <string> platforms, int _v, int _g) {	
		g=_g;v=_v;
		N=platforms.sz;	
		REP(i,0,N){
			istringstream is(platforms[i]);
			int a,b,c;
			is>>a>>b>>c;
			P[i]=Node(a,b,c);

		}
		int ans=0;
		sort(P,P+N);
		REP(i,0,N){
			fill(dp,-1);
			ans=max(ans,go(i));		
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	PlatformJumper *obj;
	int answer;
	obj = new PlatformJumper();
	clock_t startTime = clock();
	answer = obj->maxCoins(p0, p1, p2);
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
	
	vector <string> p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	string t0[] = {"3 10 7","5 15 7","8 9 12"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 10;
	p3 = 14;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0 0 1","2 4 1","4 0 1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 2;
	p3 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0 0 1","5000 5000 10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	p2 = 87;
	p3 = 10;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"1 5000 10","1024 1156 1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 99;
	p2 = 72;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, false, p3) && all_right;
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
