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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
typedef long long ll;
int di[]={0,0,1,-1,1,-1,1,-1, 2,1,-1,-2,-1,-2,1,2};
int dj[]={1,-1,0,0,1,-1,-1,1, 1,2,-2,-1,2,1,-2,-1};

bool vis[10][10];
vector<string> board;
int dfs(int r, int c){
	vis[r][c]=1;
	int ans=1;
	REP(i,0,8){
		REP(j,0,8){
			int X=r+dj[8+j];
			int Y=c+dj[8+j];
			if(min(X,Y)>=0 && max(X,Y)<8 && !vis[X][Y] && board[X][Y]!='*')
				ans+=dfs(X,Y);
		}
	}
	return ans;
}


class KnightsTour {
public:int visitedPositions(vector <string> board) {	
		::board=board;			
		fill(vis,0);
		REP(i,0,8)
			REP(j,0,8)
				if(board[i][j]=='K')
					return dfs(i,j);
		return 0;
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	KnightsTour *obj;
	int answer;
	obj = new KnightsTour();
	clock_t startTime = clock();
	answer = obj->visitedPositions(p0);
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
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"........",".*.*....",".*......","..K...*.","*...*...","...*....","...*.*..","........"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 39;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"K.......","........","........","........","........","........","........","........"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 64;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"********","*******.","********","**.***.*","********","***.*.**","********","****K***"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"*.*....*",".......*","**...*..","..***...",".**.*...","..*.*..K","..***.*.","**...*.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 17;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"..*...*.","**.....*","*..*....","*..*....",".....*..","....*..K","**.*...*","..**...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 27;
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
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
