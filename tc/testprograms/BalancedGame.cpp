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
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}
class BalancedGame {
public:int result(vector <string> c, int p, int q) {	
		f(i,c.sz){
			double a=0,b=0,n=c[i].sz-1;
			f(j,c[i].sz){
				if(i==j)continue;
				if(c[i][j]=='W')a++;
				if(c[i][j]=='L')b++;
			}
			if(ceil(a*100)/n<p || ceil(b*100)/n<q)return i;
		}
		return -1;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
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
	BalancedGame *obj;
	int answer;
	obj = new BalancedGame();
	clock_t startTime = clock();
	answer = obj->result(p0, p1, p2);
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
	string t0[] = {"TWWW","LTWW","LLTW","LLLT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	p2 = 20;
	p3 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"TWWW","LTWW","LLTW","LLLT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	p3 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"TTT","TTT","TTT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 1;
	p3 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"TLLLLLTWWWWTLLWWWT","WTTWTTLLWLLWWLTLWW","WTTWWTLWTWLWWWWLTW","WLLTLTWWWTWLWLLWLT","WTLWTLWWWWLLWLLWTW","WTTTWTWLLWTLLWWWLW","TWWLLLTLLWTWWWLLWW","LWLLLWWTWLLWWLLLWT","LLTLLWWLTTWLTWTLWT","LWLTLLLWTTTLLLLWTW","LWWLWTTWLTTTLLWWLL","TLLWWWLLWWTTLWTTLL","WLLLLWLLTWWWTWLLWW","WWLWWLLWLWWLLTTWLL","LTLWWLWWTWLTWTTTWT","LWWLLLWWWLLTWLTTLW","LLTWTWLLLTWWLWLWTW","TLLTLLLTTLWWLWTLLT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 18;
	p2 = 6;
	p3 = 17;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
