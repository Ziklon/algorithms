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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}

class RouteIntersection {
public:string isValid(int N, vector <int> coords, string moves) {	
				
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, string p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	RouteIntersection *obj;
	string answer;
	obj = new RouteIntersection();
	clock_t startTime = clock();
	answer = obj->isValid(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	int p0;
	vector <int> p1;
	string p2;
	string p3;
	
	{
	// ----- test 0 -----
	p0 = 1;
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+";
	p3 = "VALID";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	int t1[] = {1,2,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "++--";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	int t1[] = {1,2,3,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+++--";
	p3 = "VALID";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 344447;
	int t1[] = {132,51717,628,344447,628,51717,344447,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+-++-+--";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	int t1[] = {1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+-";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 990630;
	int t1[] = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,623194,940783,571384,988451,108056,514374,97664};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "--+---+-+++-+-+---++-++-+---+-+--+-++";
	p3 = "NOT VALID";
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
