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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

bool equals(string s, string x){
	for(int i=0;i<s.sz;i++){
		if(s[i]!=x[i] && x[i]!='?' && s[i]!='?')
			return 0;
	}
	return 1;
}
bool contains(string s, string x){
	if(s.sz<x.sz)return 0;
	int n=x.sz;
	for(int i=0;i+n<=s.sz;i++){
		string aux=s.substr(i,n);
		if(equals(aux,x))return 1;
	}
	return 0;
}

class TwoWords {
public:string howMany(string s, string a, string b) {	
		if(a.sz<b.sz)
			swap(a,b);
		int n=a.sz;
		int dev=0;
		for(int i=0;i+a.sz<=s.sz;i++){
			string x=s.substr(0,i);
			string y=s.substr(i,n);
			string z=s.substr(i+n);
			dev=max(dev, contains(y,a) + (contains(x,b) || contains(z,b)));
		}
		n=b.sz;
		for(int i=0;i+n<=s.sz;i++){
			string x=s.substr(0,i);
			string y=s.substr(i,n);
			string z=s.substr(i+n);
			dev=max(dev, contains(y,b) + (contains(x,a) || contains(z,a)));
		}
		
		if(dev>=2)return "both";
		if(dev==1)return "one";
		return "none";	
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, string p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	TwoWords *obj;
	string answer;
	obj = new TwoWords();
	clock_t startTime = clock();
	answer = obj->howMany(p0, p1, p2);
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
	
	string p0;
	string p1;
	string p2;
	string p3;
	
	{
	// ----- test 0 -----
	p0 = "yello?" "?taxi";
	p1 = "yellow";
	p2 = "taxi";
	p3 = "both";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "?ellowtaxi";
	p1 = "yell";
	p2 = "l?w";
	p3 = "one";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "tha?isunbelievable";
	p1 = "han?y";
	p2 = "?th?";
	p3 = "none";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "secondfirst";
	p1 = "second";
	p2 = "first";
	p3 = "both";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "me?sa?e";
	p1 = "?ceage";
	p2 = "essay";
	p3 = "one";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "?";
	p1 = "?" "?";
	p2 = "?" "?" "?";
	p3 = "none";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "hello";
	p1 = "h?";
	p2 = "ll?";
	p3 = "both";
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
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
