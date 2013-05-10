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

struct WolfInZooDivOne {
   int count( int N, vector <string> L, vector <string> R ) {
		
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
		cout << "Testing WolfInZooDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367545904;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WolfInZooDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				string L[] = {"0"};
				string R[] = {"4"};
				_expected = 16;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 5;
				string L[] = {"0 1"};
				string R[] = {"2 4"};
				_expected = 21;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 10;
				string L[] = {"0 4 2 7"};
				string R[] = {"3 9 5 9"};
				_expected = 225;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 100;
				string L[] = {"0 2 2 7 10 1","3 16 22 30 33 38"," 42 44 49 51 57 60 62"," 65 69 72 74 77 7","8 81 84 88 91 93 96"};
				string R[] = {"41 5 13 22 12 13 ","33 41 80 47 40 ","4","8 96 57 66 ","80 60 71 79"," 70 77 ","99"," 83 85 93 88 89 97 97 98"};
				_expected = 6419882;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}
			/*case 4:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int N = ;
				string L[] = ;
				string R[] = ;
				_expected = ;
				_received = _obj.count(N, vector <string>(L, L+sizeof(L)/sizeof(string)), vector <string>(R, R+sizeof(R)/sizeof(string))); break;
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
