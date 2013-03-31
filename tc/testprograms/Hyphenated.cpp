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
using namespace std;
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

class Hyphenated {
public:double avgLength(vector <string> lines) {	
		vector<int> v;
		string text="";
		REP(i,0,lines.sz){
			int n=text.sz;
			if(text!="" && lines[i-1].sz>=2){
				if(text[n-1]=='-' && isalpha(text[n-2]) && isalpha(lines[i][0])){
					text[n-1]='=';
				}else
					text+=' ';
				cout<<"yeah"<<endl;
			}else
				text+=' ';
			text+=lines[i];			
		}
		cout<<text<<endl;
		REP(i,0,text.sz)if(!isalpha(text[i]) && text[i]!='=')text[i]=' ';
		stringstream ss(text);
		double sum=0;
		int N=0;
		while(ss>>text){
			N++;
			sum+=text.sz-count(all(text),'=');

		}
		return sum/N;	
	}

};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Hyphenated *obj;
	double answer;
	obj = new Hyphenated();
	clock_t startTime = clock();
	answer = obj->avgLength(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	double p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"  now is the ex-","ample.  "};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3.75;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"  now is the ex-"," ample.  "};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3.0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"inter-","national-","ization.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20.0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"All the time I have well-defined  "," trouble."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4.125;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"hello-","-","-","-","great"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5.0;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"A-B","C"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
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
