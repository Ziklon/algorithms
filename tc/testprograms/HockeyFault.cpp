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
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int pw(int a){
	return a*a;
}
class HockeyFault {
public:int numPlayers(int width, int height, int x, int y, vector <int> px, vector <int> py) {	
		int dev=0;
		int r=height/2,X,Y;
		X=x+width;
		Y=y+r;
		for(int i=0;i<px.sz;i++){
			if(px[i]>=x && px[i]<=x+width && py[i]>=y && py[i]<=y+height){
				dev++;
				continue;
			}
			if((pw(px[i]-x)+pw(py[i]-Y))<=r*r  || (pw(px[i]-X)+pw(py[i]-Y))<=r*r )
				dev++;			
		}
		return dev;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, vector <int> p4, vector <int> p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p4[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p5.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p5[i];
	}
	cout << "}";
	cout << "]" << endl;
	HockeyFault *obj;
	int answer;
	obj = new HockeyFault();
	clock_t startTime = clock();
	answer = obj->numPlayers(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	int p1;
	int p2;
	int p3;
	vector <int> p4;
	vector <int> p5;
	int p6;
	
	{
	// ----- test 0 -----
	p0 = 20;
	p1 = 10;
	p2 = 5;
	p3 = 0;
	int t4[] = {15,1,1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	int t5[] = {5,5,1};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	p6 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 20;
	p1 = 10;
	p2 = 0;
	p3 = 0;
	int t4[] = {-5,-4,-4,-3,-3,0,0,20,20,23,23,24,24,25};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	int t5[] = {5,2,8,1,9,0,10,0,10,1,9,2,8,5};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	p6 = 14;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 52;
	p1 = 84;
	p2 = -44;
	p3 = 66;
	int t4[] = {26,-33,-49,40,-10,47,25,-16,-82,7};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	int t5[] = {118,106,128,114,101,85,142,140,126,145};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	p6 = 8;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 24;
	p1 = 100;
	p2 = -61;
	p3 = 71;
	int t4[] = {-63,-26,-9,-113,-124,-95,-89,-55};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	int t5[] = {109,164,91,80,75,140,116,113};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	p6 = 6;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
