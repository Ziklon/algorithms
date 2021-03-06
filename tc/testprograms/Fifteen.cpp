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

int dp[1<<9][1<<9][2];

bool check(int mask){
	vector<int> v;
	for(int i=0;i<9;i++)if(mask&(1<<i))v.push_back(i+1);
	int n=v.size();
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++){
		if(v[i]+v[j]+v[k]==15)return 1;
	}
	return 0;
}

int go(int maskA, int maskB, int who){
	if(check(maskB))return 1;	
	if(check(maskA))return 0;	
	vector<int> v(9,0);
	for(int i=0;i<9;i++)if(maskA&(1<<i))v[i]=1;
	for(int i=0;i<9;i++)if(maskB&(1<<i))v[i]=1;
	int& ref=dp[maskA][maskB][who];	
	if(who){
		ref=0;
		for(int i=0;i<9;i++)if(v[i]==0){
			ref=max(ref,go(maskA,maskB|(1<<i),0));
		}

	}else{
		ref=1;
		for(int i=0;i<9;i++)if(v[i]==0){
			ref=min(ref,go(maskA|(1<<i),maskB,1));
		}
	}
	return ref;			
}

class Fifteen {
public:string outcome(vector <int> moves) {	
		int maskA=0;
		int maskB=0;
		int N=moves.size();
		vector<int> used(9,0);
		for(int i=0;i<moves.size();i++){
			used[moves[i]-1]=1;
			if(i&1) maskB|=(1<<(moves[i]-1));
			else maskA|=1<<(moves[i]-1);	
		}

		int mask=0;
		memset(dp,-1,sizeof dp);		
		int ret=1<<20;		
		for(int i=0;i<9;i++){
			if(used[i]==0 && go(maskA,maskB|(1<<i),0)==1){
				ret=i+1;
				break;
			}
		}		
		if(ret<=9){
			char ans[20];
			sprintf(ans,"WIN %d",ret);
			return ans;
		}
		return "LOSE";		
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
	Fifteen *obj;
	string answer;
	obj = new Fifteen();
	clock_t startTime = clock();
	answer = obj->outcome(p0);
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
	int t0[] = {7,5,9,6,8,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "WIN 4";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {4,8,6,5,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "LOSE";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2,4,7,6,9,8,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "WIN 1";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {9,2,1,6,3,4,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "WIN 5";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "LOSE";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {6,3,7,8,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "WIN 2";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {1,8,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	all_right = KawigiEdit_RunTest(6, p0, false, p1) && all_right;
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
