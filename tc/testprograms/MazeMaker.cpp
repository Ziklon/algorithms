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
bool vis[51][51];
int dis[51][51];
struct node{
	int x,y,c;
	node(int _x, int _y, int _c){
		x=_x;
		y=_y;
		c=_c;
	}
};

class MazeMaker {
public:int longestPath(vector <string> maze, int _xs, int _ys, vector <int> di, vector <int> dj) {	
		mem(vis,0);
		int dev=0;
		queue<node>Q;
		Q.push(node(_xs,_ys,0));
		vis[_xs][_ys]=1;
		for(int i=0;i<51;i++)
			for(int j=0;j<51;j++)
				dis[i][j]=1<<30;
				
		while(!Q.empty()){
			node cur=Q.front();
			Q.pop();	
			dis[cur.x][cur.y]=cur.c;		
			for(int k=0;k<di.sz;k++){
				int X=cur.x+di[k];
				int Y=cur.y+dj[k];
				if(X>=0 && Y>=0 && X<maze.sz && Y<maze[0].sz && maze[X][Y]!='X' && !vis[X][Y]){
					Q.push(node(X,Y,cur.c+1));
					vis[X][Y]=1;
				}					
			}
		}
		for(int i=0;i<maze.sz;i++)
			for(int j=0;j<maze[i].sz;j++)
				if(maze[i][j]=='.')
					dev=max(dev,dis[i][j]);
		return dev==1<<30?-1:dev;
				
	}
	//Powered by [Ziklon]
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, int p2, vector <int> p3, vector <int> p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1 << "," << p2 << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p4[i];
	}
	cout << "}";
	cout << "]" << endl;
	MazeMaker *obj;
	int answer;
	obj = new MazeMaker();
	clock_t startTime = clock();
	answer = obj->longestPath(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	int p2;
	vector <int> p3;
	vector <int> p4;
	int p5;
	
	{
	// ----- test 0 -----
	string t0[] = {"...","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	int t3[] = {1,0,-1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,-1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"...","...","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	int t3[] = {1,0,-1,0,1,1,-1,-1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,-1,1,-1,1,-1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"X.X","...","XXX","X.X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	int t3[] = {1,0,-1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,-1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".......","X.X.X..","XXX...X","....X..","X....X.","......."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	p2 = 0;
	int t3[] = {1,0,-1,0,-2,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,-1,0,1,3,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 7;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"......."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	int t3[] = {1,0,1,0,1,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,1,0,1,0,1};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 6;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"..X.X.X.X.X.X."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 0;
	int t3[] = {2,0,-2,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	int t4[] = {0,2,0,-2};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = -1;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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
