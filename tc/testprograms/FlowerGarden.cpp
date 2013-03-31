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
class FlowerGarden {
public:vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {	
				
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, bool hasAnswer, vector <int> p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	FlowerGarden *obj;
	vector <int> answer;
	obj = new FlowerGarden();
	clock_t startTime = clock();
	answer = obj->getOrdering(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p3[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
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
	
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	
	{
	// ----- test 0 -----
	int t0[] = {5,4,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {365,365,365,365,365};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,2,3,4,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,4,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,5,10,15,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,9,14,19,24};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,4,3,2,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {5,4,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,5,10,15,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5,10,15,20,25};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,2,3,4,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {5,4,3,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,5,10,15,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {5,10,14,20,25};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,4,5,1,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,2,3,4,5,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,3,1,3,1,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,4,2,4,2,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,4,6,1,3,5};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {3,2,5,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,11,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,3,12,13};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {4,5,2,3};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
