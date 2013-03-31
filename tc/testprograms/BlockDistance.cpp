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

#define INF 1<<25
#define sz size()
string first,second;

int dp[1<<10][1<<10];

int go(int x,int y){

	if(x>=first.sz && y>=second.sz)return 0;
	if(x>=first.sz)return 1;
	if(y>=second.sz)return INF;

	int& ref=dp[x][y];	
	if(ref!=-1)return ref;
	ref=INF;

	for(int i=y+1;i<second.sz;i++)
		ref=min(ref,go(x,i)+1);

	if(first[x]==second[y])
		ref=min(ref,go(x+1,y+1));					

	return ref;
}

class BlockDistance {
public:
	int minDist(vector <string> oldText, vector <string> newText) {
		first="";
		second="";
		for(int i=0;i<oldText.size();i++)first+=oldText[i];
		for(int i=0;i<newText.size();i++)second+=newText[i];

		memset(dp,-1,sizeof dp);

		int ans=go(0,0);
		if(ans>=INF)return -1;

		return ans;

	}
};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	BlockDistance *obj;
	int answer;
	obj = new BlockDistance();
	clock_t startTime = clock();
	answer = obj->minDist(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"hello goodbye"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"hello, how are you? goodbye have a nice day"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"aaaaa"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ababababa"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"aaaaaaaaaaaaaaaa"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"aaaaaaaaaaaaaaaa","t","aaaaaaaaaaaaaaaa"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"no way"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"No way!"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"abce","f","ij","klm","n","op","uvwx","z"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ab","cdefg","hijklmnop","q","rs","tuv","wxyz"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
