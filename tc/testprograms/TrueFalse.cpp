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
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;

class TrueFalse {
public:string answerKey(vector <string> graded) {	
		string ans=string(20,'Z');
		int ubi=graded[0].find(' ')+1;
		int N=graded[0].size()-ubi;		
		int cntAns=0;
		REP(mask,1<<N){
			string tmp;
			REP(i,N)if(mask&(1<<i))tmp+='T';
			else tmp+='F';
			bool can=1;
			
			vector<bool> used(55,0);
			REP(i,graded.size()){
				int dif=0;
				int k=0;
				int cnt=0;
				while(isdigit(graded[i][k])){
					cnt=cnt*10+(graded[i][k]-'0');
					k++;
				}
				k++;
				REP(j,N){
					if(graded[i][j+k]!=tmp[j])dif++;
					else used[j]=1;
				}
				if(dif!=(N-cnt))can=0;	
			}
			REP(i,N)if(used[i]==0)can=0;
			
			if(can){
				cntAns++;
				ans=min(ans,tmp);
			}	
			
		}
		if(cntAns==0)return "inconsistent";		
		return ans;		
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
	TrueFalse *obj;
	string answer;
	obj = new TrueFalse();
	clock_t startTime = clock();
	answer = obj->answerKey(p0);
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
	string t0[] = {"2 TTF","1 FTF","2 FTT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "TTT";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"7 TTFFTFT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "TTFFTFT";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"9 TTTFFFFTTFFTTFT","7 FFFFFFFFFFFFFFF"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "inconsistent";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"9 TTTFFFFTTFFTTFT","7 FFFFFFFFFFFFFFF","8 TTTTTTTTTTTTTTT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "FFFFFFFTTTTTTTT";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
