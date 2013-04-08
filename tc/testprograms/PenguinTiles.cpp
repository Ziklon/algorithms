#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;

struct PenguinTiles {
   int minMoves( vector <string> tiles ) {
		int ans=1;
		int n=tiles.size();
		int m=tiles[0].size();
		int x,y;
		REP(i,n)REP(j,m){
			if(tiles[i][j]=='.'){
				x=i;
				y=j;
			}
		}
		if(x==n-1 && y==m-1)return 0;
		if(x==n-1 || y==m-1)return 1;
		return 2;
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
		cout << "Testing PenguinTiles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358023742;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PenguinTiles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tiles[] = {"PP",
				                  "P."};
				_expected = 0;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 1:
			{
				string tiles[] = {"PPPPPPPP",
				                  ".PPPPPPP"};
				_expected = 1;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 2:
			{
				string tiles[] = {"PPP",
				                  "P.P",
				                  "PPP"};
				_expected = 2;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 3:
			{
				string tiles[] = {"P.",
				                  "PP",
				                  "PP",
				                  "PP"};
				_expected = 1;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			case 4:
			{
				string tiles[] = {".PPP",
				                  "PPPP",
				                  "PPPP",
				                  "PPPP"};
				_expected = 2;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}
			/*case 5:
			{
				string tiles[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string tiles[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string tiles[] = ;
				_expected = ;
				_received = _obj.minMoves(vector <string>(tiles, tiles+sizeof(tiles)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
