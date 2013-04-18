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
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
typedef long long ll; 
int dx[]={0,0,1,-1,1,-1,1,-1,0};
int dy[]={1,-1,0,0,1,-1,-1,1,0};

struct BombSweeper {
   double winPercentage( vector <string> board ) {
		double wins=0;
		int cnt=0;
		REP(i,board.size())REP(j,board[i].size()){
            if(board[i][j]=='B'){
                cnt++;
                continue;
            }
            bool can=1;
            REP(k,8){
               int X=i+dx[k];
               int Y=j+dy[k];
               if(min(X,Y)>=0 && X<board.size() && Y<board[0].size() && board[X][Y]=='B')can=0; 
            }
            if(can)wins+=1;
		}
		return (100.0*wins)/(wins+cnt);
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
		cout << "Testing BombSweeper (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366221255;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BombSweeper _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".....",
				                  ".....",
				                  "..B..",
				                  ".....",
				                  "....."};
				_expected = 94.11764705882354;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"BBBBB",
				                  "B...B",
				                  "B...B",
				                  "B...B",
				                  "BBBBB"};
				_expected = 5.882352941176471;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".........",
				                  ".B..B..B.",
				                  ".........",
				                  ".........",
				                  ".B..B..B.",
				                  ".........",
				                  ".........",
				                  ".B..B..B.",
				                  "........."};
				_expected = 0.0;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".........................",
				                  ".........................",
				                  ".........................",
				                  "........................."};
				_expected = 100.0;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"......B.......B..B...........................B....",
				                  "..............B..................BB..B............",
				                  "B.B.B.............B.....B..............B..........",
				                  "...................B...B....................BB....",
				                  "...B.....B.........................B.......B.....B",
				                  "B.B.........B.....B.......B..B......B.B...B.BB....",
				                  "..B...................BB...............B..........",
				                  ".........B...B................B..B................",
				                  ".......BB.......B....B................B.....BBB...",
				                  ".......BB..........B..............B......BB.......",
				                  "...................BB.....................B.......",
				                  "...B.B.B......B..............B...B......B.........",
				                  "B................B................................",
				                  "....B..........B.....B..BB....B...............BB..",
				                  "..B....B.....B.............B.....B............B...",
				                  "...................B.B........B..B.........B.B....",
				                  ".....B.....B......................................",
				                  "...........BB......BB...B.B........B...B..........",
				                  ".....BBB..........................................",
				                  ".B...........B....B...BB......B......B...B.B......",
				                  "..................B........BB................B....",
				                  "...............................B..B....BBB.B....B.",
				                  "..........B.......................................",
				                  ".....B..........B....BB......B.B......B......B....",
				                  ".....B..................B........B................",
				                  "............B.....B..B....BB...B....BB........B...",
				                  "..B.................B.........B...................",
				                  ".BB..............B................................",
				                  "...B....B..................B.................B....",
				                  "......B...B......B......................B.B.......",
				                  "..............B..................B.......B........",
				                  ".....B........BB...B.....B........................",
				                  ".......B......B.B..B..........B...........B....B..",
				                  "B...B...........B...B...B......B.B...B..B......B..",
				                  "....B..B.....B.B.......BB..B............B.B....B..",
				                  "B.......B..........B.........B...B.BB......B......",
				                  "....B...............................B.............",
				                  ".....B.B..........................................",
				                  "..........B............B......B.B..B....B.........",
				                  "....B...B.......................B.................",
				                  "B.................B...........B..B....B...........",
				                  "...B.....B........................................",
				                  "...B..B......................................BBB..",
				                  ".B...B....................................B....B..",
				                  "...B...B..........B...B.B.........................",
				                  ".....B.............B...BB..........B..BBB.BB......",
				                  "....................B.....B.......................",
				                  "........B..BB..........B.B....B...........B......B",
				                  ".........B.....BB..B.............B....BB..........",
				                  "....B..B..............B...B..B..........B........."};
				_expected = 77.67558528428094;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.winPercentage(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
