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
using namespace std;
#define REP(i,n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int memo[4000001];
int P[11];

int sum(int a){
	int ans=0;
	while(a>0){
		ans+=P[a%10];
		a/=10;
	}
	return ans; 
}

int go(int x){
	if(memo[x]>0)return memo[x];	
	if(memo[x]==-1){
		int mini=x;
		int tmp=x;
		while(1){
			tmp=sum(tmp);
			mini=min(mini,tmp);
			if(tmp==x)break;
		}
		memo[x]=mini;
		return mini;	
	}
	memo[x]=-1;
	memo[x]=min(x,go(sum(x)));	
	return memo[x];
}
class ExtendedHappyNumbers {
public:
	long long calcTheSum(int A, int B, int K) {
		memset(memo,0,sizeof memo);
		ll ans=0;
		
		for(int i=0;i<10;i++){
			int tmp=1;
			for(int j=0;j<K;j++)tmp*=i;
			P[i]=tmp;
			
		}				
		for(int i=A;i<=B;i++)ans+=go(i);
		return ans;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	ExtendedHappyNumbers *obj;
	long long answer;
	obj = new ExtendedHappyNumbers();
	clock_t startTime = clock();
	answer = obj->calcTheSum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	int p1;
	int p2;
	long long p3;
	
	{
	// ----- test 0 -----
	p0 = 13;
	p1 = 13;
	p2 = 2;
	p3 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 5;
	p2 = 2;
	p3 = 14ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = 99;
	p2 = 1;
	p3 = 450ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 535;
	p1 = 538;
	p2 = 3;
	p3 = 820ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100000;
	p1 = 400000;
	p2 = 6;
	p3 = 5169721292ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
