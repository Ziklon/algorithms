#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

struct WhiteCells {
   int countOccupied( vector <string> board ) {
        int ans=0;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				if((i+j)%2==0 && board[i][j]=='F')
					ans++;
		return ans;

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
		cout << "Testing WhiteCells (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356643700;
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
		WhiteCells _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........"};
				_expected = 0;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF",
				                  "FFFFFFFF"};
				_expected = 32;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".F.F...F",
				                  "F...F.F.",
				                  "...F.F.F",
				                  "F.F...F.",
				                  ".F...F..",
				                  "F...F.F.",
				                  ".F.F.F.F",
				                  "..FF..F."};
				_expected = 1;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"........",
				                  "..F.....",
				                  ".....F..",
				                  ".....F..",
				                  "........",
				                  "........",
				                  ".......F",
				                  ".F......"};
				_expected = 2;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.countOccupied(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
