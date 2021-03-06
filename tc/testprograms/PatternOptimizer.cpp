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

string cs="*?";

class PatternOptimizer {
public:string optimize(string pattern) {	
		node:	
		while(1){
			for(int i=pattern.sz-1;i>=0;i--){
				if(pattern[i]=='*')	

				REP(k,0,2){
					int j=i+k;
					int a=0;
					while(j<pattern.sz&&pattern[j]==cs[k]){
						a++;
						j++;
					}
					if(k==0 && a>1){
						pattern=pattern.substr(0,i)+"*"+pattern.substr(j);
						goto node;
					}
					if(k==1 && a>0 && j<pattern.sz && pattern[j]=='*'){
						pattern=pattern.substr(0,i+1)+string(a,'?')+pattern.substr(j+1);
						cout<<"hhe"<<endl;
						goto node;	
					}

				}

			}
			break;
		}

		REP(i,1,pattern.sz){
			if(pattern[i]=='*' && pattern[i-1]=='?'){
				int j=i-1;
				while(j>=0 && pattern[j]=='?')j--;

				swap(pattern[i],pattern[j+1]);
			}
		}
		return pattern;

	}

};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	PatternOptimizer *obj;
	string answer;
	obj = new PatternOptimizer();
	clock_t startTime = clock();
	answer = obj->optimize(p0);
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
	
	string p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = "*?" "?*a";
	p1 = "*?" "?a";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "*b**a*";
	p1 = "*b*a*";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "cla?" "?";
	p1 = "cla?" "?";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "*?*?*?*";
	p1 = "*?" "?" "?";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "T***nd?*";
	p1 = "T*nd*?";
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
// END KAWIGIEDIT TESTING//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
//With unused code cleaner (beta) by ahmed_aly
