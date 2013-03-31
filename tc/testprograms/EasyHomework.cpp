#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

class EasyHomework {
public:string determineSign(vector <int> A) {	
		string ans="POSITIVE";
		int pos=0;
		int neg=0;
		for(int i=0;i<A.size();i++){
			if(A[i]==0)return "ZERO";
			if(A[i]<0)neg++;
		}
		if(neg&1)return "NEGATIVE";
		return ans;		
	}
};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	EasyHomework *obj;
	string answer;
	obj = new EasyHomework();
	clock_t startTime = clock();
	answer = obj->determineSign(p0);
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {5,7,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSITIVE";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {-5,7,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NEGATIVE";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {5,7,2,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "ZERO";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {3,-14,159,-26};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSITIVE";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-1000000000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "NEGATIVE";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {123,-456,789,-101112,131415,161718,192021,222324,252627,282930,313233,343536,373839,404142,434445,464748,495051,525354,555657};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSITIVE";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
