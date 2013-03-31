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
class KnightTour {
public:string checkTour(vector <string> cell) {	
		set<string> S(all(cell));
		if(S.sz!=36)return "Invalid";
		for(int i=0;i+1<cell.sz;i++){
			int a=abs(cell[i+1][0]-cell[i][0]);
			int b=abs(cell[i+1][1]-cell[i][1]);
			if((a==1 && b==2) || (a==2&& b==1))continue;
			return "Invalid";
		}
		int a=abs(cell[35][0]-cell[0][0]);
		int b=abs(cell[35][1]-cell[0][1]);
		if((a==1 && b==2) || (a==2&& b==1))return "Valid";
		return "Invalid";	
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
	KnightTour *obj;
	string answer;
	obj = new KnightTour();
	clock_t startTime = clock();
	answer = obj->checkTour(p0);
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
	string t0[] = {"A1","B3","A5","C6","E5","F3","D2","F1","E3","F5","D4","B5","A3","B1","C3","A2","C1","E2","F4","E6","C5","A6","B4","D5","F6","E4","D6","C4","B6","A4","B2","D1","F2","D3","E1","C2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Valid";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3","A1","C2","E3","F5","D4","B3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Invalid";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"D4","F5","D6","B5","A3","B1","D2","F1","E3","D1","F2","E4","F6","D5","B6","A4","B2","C4","A5","C6","E5","F3","E1","C2","A1","B3","C5","E6","F4","E2","C3","A2","C1","D3","B4","A6"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Invalid";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"D4","F5","D6","B5","A3","B1","D2","F1","E3","D1","F2","E4","F6","D5","B6","A4","B2","C4","A5","C6","E5","F3","E1","C2","A1","B3","C5","A6","B4","A2","C3","E2","C1","D3","F4","E6"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Valid";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"C5","D3","F2","D1","B2","A4","B6","D5","C3","E4","F6","B3","A1","C2","E1","F3","E5","C6","A5","C4","A3","B1","D2","F1","E3","F5","D6","B5","D4","E6","F4","E2","C1","A2","B4","A6"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Invalid";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
