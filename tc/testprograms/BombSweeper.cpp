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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}

int di[8]={0,0,1,-1,1,-1,-1,1};
int dj[8]={1,-1,0,0,1,1,-1,-1};

class BombSweeper {
public:double winPercentage(vector <string> board) {	
		int cnt=0;
		int lose=0;
		int h=board.sz;
		int w=board[0].sz;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){				
				if(board[i][j]=='B'){
					lose++;
					continue;
				}
				bool ok=1;
				for(int k=0;k<8;k++){
					int x=i+di[k];
					int y=j+dj[k];
					if(x>=0 && x<h && y>=0 && y<w)
						if(board[x][y]=='B'){
							ok=0;
							break;
						}
				}
				if(ok)cnt++;
			}
		}
		return ((double)cnt/double(cnt+lose))*100;
	}
	//Powered by [Ziklon]
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
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
	BombSweeper *obj;
	double answer;
	obj = new BombSweeper();
	clock_t startTime = clock();
	answer = obj->winPercentage(p0);
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
		res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	string t0[] = {".....",".....","..B..",".....","....."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 94.11764705882354;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"BBBBB","B...B","B...B","B...B","BBBBB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5.882352941176471;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {".........",".B..B..B.",".........",".........",".B..B..B.",".........",".........",".B..B..B.","........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".........................",".........................",".........................","........................."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100.0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"......B.......B..B...........................B....","..............B..................BB..B............","B.B.B.............B.....B..............B..........","...................B...B....................BB....","...B.....B.........................B.......B.....B","B.B.........B.....B.......B..B......B.B...B.BB....","..B...................BB...............B..........",".........B...B................B..B................",".......BB.......B....B................B.....BBB...",".......BB..........B..............B......BB.......","...................BB.....................B.......","...B.B.B......B..............B...B......B.........","B................B................................","....B..........B.....B..BB....B...............BB..","..B....B.....B.............B.....B............B...","...................B.B........B..B.........B.B....",".....B.....B......................................","...........BB......BB...B.B........B...B..........",".....BBB......................................"
			"....",".B...........B....B...BB......B......B...B.B......","..................B........BB................B....","...............................B..B....BBB.B....B.","..........B.......................................",".....B..........B....BB......B.B......B......B....",".....B..................B........B................","............B.....B..B....BB...B....BB........B...","..B.................B.........B...................",".BB..............B................................","...B....B..................B.................B....","......B...B......B......................B.B.......","..............B..................B.......B........",".....B........BB...B.....B........................",".......B......B.B..B..........B...........B....B..","B...B...........B...B...B......B.B...B..B......B..","....B..B.....B.B.......BB..B............B.B....B..","B.......B..........B.........B...B.BB......B......","....B...............................B.............",".....B.B................................"
			"..........","..........B............B......B.B..B....B.........","....B...B.......................B.................","B.................B...........B..B....B...........","...B.....B........................................","...B..B......................................BBB..",".B...B....................................B....B..","...B...B..........B...B.B.........................",".....B.............B...BB..........B..BBB.BB......","....................B.....B.......................","........B..BB..........B.B....B...........B......B",".........B.....BB..B.............B....BB..........","....B..B..............B...B..B..........B........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 77.67558528428094;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
