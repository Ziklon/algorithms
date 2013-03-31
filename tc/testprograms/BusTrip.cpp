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
class BusTrip {
public:int returnTime(int N, vector <string> buses) {	
		int dev=1<<30,ante,aux,tmp,first;
		bool ok=0;
		for(int i=0;i<buses.sz;i++){
			istringstream is(buses[i]);
			tmp=0;
			ante=0;
			while(is>>aux){
				tmp+=abs(ante-aux);
				ante=aux;
			}
			tmp+=ante;
			cout<<N*tmp<<endl;
			if(N*tmp<=1000){
				ok=1;
				dev=min(N*tmp,dev);
			}
		}
		if(ok)return dev;
		return -1;		
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	BusTrip *obj;
	int answer;
	obj = new BusTrip();
	clock_t startTime = clock();
	answer = obj->returnTime(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	string t1[] = {"0 1 2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 12;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 51;
	string t1[] = {"0 5 10 15 20 25 30 35 40 50"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1000;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	string t1[] = {"0 1 2","2 1 0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	string t1[] = {"0 1 2 3 4","3 1 2 0","4 1 2 3 0","1 2 0 3 4","4 0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 12;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 25;
	string t1[] = {"24 14 9 7 2","21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22","12 22 24 9 1 5 10 8 7 18 16 19 4 13 17","14 5 17 9 23 7 16 22 10 4 6","19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15","2 16 10 13 14 1 11 20 0 24 22 23 19 4 18","19 15 18 0","15 9 22 5 20 8 23 14 24 18 21 6 13 19","2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5","19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 157;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 100;
	string t1[] = {"0 10 30 45 60 46 39 31 20","9 20 0 86"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
