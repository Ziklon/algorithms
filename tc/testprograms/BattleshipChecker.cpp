#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <deque> 
#include <queue> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <cmath> 
#include <cstdlib> 
#include <ctime>
#include <cstring>
#include <cstdio>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
typedef long long ll; 

bool seen[11][11];
int B[10]={};
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

int nodes,childs;
void dfs(int x, int y , vector<string>& v){
    nodes++;
    seen[x][y]=1;
    int tmp=0;    
    REP(i,8){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(min(X,Y)>=0 && max(X,Y)<10 && seen[X][Y]==0 && v[X][Y]=='X'){
            if(i>=4)
                childs=4;
            else{
                dfs(X,Y,v);
                tmp++;
            }
        }
    }
    childs=max(childs,tmp);
}

struct BattleshipChecker {
   string checkBoard( vector <string> board ) {
		
		REP(i,10)REP(j,10)if(board[i][j]=='X' && seen[i][j]==0){
           nodes=childs=0;
           dfs(i,j,board);
           if(nodes>4 || childs>1)return "REJECTED";
           B[nodes]++;                       
		}		
		REP(i,4)if(B[i+1]!=4-i)return "REJECTED";
		int ret=0;
		REP(i,10){
            int ok1=1,ok2=1;
            REP(j,10)if(board[i][j]=='X')ok1=0;
            REP(j,10)if(board[j][i]=='X')ok2=0;
            ret+=ok1;
            ret+=ok2;
		}
		char buff[124];
		sprintf(buff,"ACCEPTED, %d POINTS",ret);
		return buff;
		
   }
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing BattleshipChecker (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366684400;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BattleshipChecker _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"......X...",
				                  ".XXX..X...",
				                  "......X...",
				                  "X.X...X...",
				                  "X.........",
				                  "...XX.X...",
				                  "......X...",
				                  ".XX...X...",
				                  "..........",
				                  ".X.X..X..."};
				_expected = "ACCEPTED, 5 POINTS";
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"X.X.X.X...",
				                  "......X...",
				                  ".XX...X...",
				                  "......X...",
				                  "......X..X",
				                  "...X..X...",
				                  "...X..X...",
				                  "......X...",
				                  "..XX..X...",
				                  "......X..."};
				_expected = "REJECTED";
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".....XX...",
				                  ".XX.......",
				                  "..........",
				                  ".X....XXX.",
				                  ".X........",
				                  ".....X....",
				                  "..X..X....",
				                  ".....X....",
				                  "...X......",
				                  "X.....XXXX"};
				_expected = "REJECTED";
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".....XX..X",
				                  ".XX......X",
				                  "..........",
				                  ".X....XXX.",
				                  ".X........",
				                  ".....X..X.",
				                  "..X..X....",
				                  ".....X....",
				                  "...X......",
				                  "X.....XXXX"};
				_expected = "REJECTED";
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"X.......X.",
				                  "...XXXX...",
				                  ".X......X.",
				                  "....XX....",
				                  ".........X",
				                  ".........X",
				                  ".....XXX..",
				                  ".........X",
				                  "..X......X",
				                  "..X......X"};
				_expected = "ACCEPTED, 0 POINTS";
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"X.......X.",
				                  "...XXXX...",
				                  ".X......X.",
				                  "....XX....",
				                  "...X.....X",
				                  "...X.....X",
				                  ".....XXX..",
				                  ".........X",
				                  ".........X",
				                  ".........X"};
				_expected = "REJECTED";
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.checkBoard(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
