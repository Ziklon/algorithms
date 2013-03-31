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

struct IsoscelesTriangulations {
   int getCount( int n, int k ) {
		int ans;	
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
		cout << "Testing IsoscelesTriangulations (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358453302;
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
		IsoscelesTriangulations _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int k = 2;
				_expected = 2;
				_received = _obj.getCount(n, k); break;
			}
			case 1:
			{
				int n = 3;
				int k = 0;
				_expected = 0;
				_received = _obj.getCount(n, k); break;
			}
			case 2:
			{
				int n = 5;
				int k = 3;
				_expected = 5;
				_received = _obj.getCount(n, k); break;
			}
			case 3:
			{
				int n = 6;
				int k = 2;
				_expected = 12;
				_received = _obj.getCount(n, k); break;
			}
			case 4:
			{
				int n = 10;
				int k = 8;
				_expected = 10;
				_received = _obj.getCount(n, k); break;
			}
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.getCount(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.getCount(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.getCount(n, k); break;
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
