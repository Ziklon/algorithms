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

struct NinjaTurtles {
   int countOpponents( int P, int K ) {
		int ans=0;	

		for(unsigned i=0;i<=100000000;i++){
			int bb=(i/K)*3;
			int aa=(i/3);
			if(bb+aa==P)return i;
		}
		return -1;
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
		cout << "Testing NinjaTurtles (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358770203;
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
		NinjaTurtles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P = 5;
				int K = 4;
				_expected = 6;
				_received = _obj.countOpponents(P, K); break;
			}
			case 1:
			{
				int P = 1;
				int K = 4;
				_expected = 3;
				_received = _obj.countOpponents(P, K); break;
			}
			case 2:
			{
				int P = 13;
				int K = 6;
				_expected = -1;
				_received = _obj.countOpponents(P, K); break;
			}
			case 3:
			{
				int P = 13;
				int K = 17;
				_expected = 30;
				_received = _obj.countOpponents(P, K); break;
			}
			case 4:
			{
				int P = 122;
				int K = 21;
				_expected = 258;
				_received = _obj.countOpponents(P, K); break;
			}
			/*case 5:
			{
				int P = ;
				int K = ;
				_expected = ;
				_received = _obj.countOpponents(P, K); break;
			}*/
			/*case 6:
			{
				int P = ;
				int K = ;
				_expected = ;
				_received = _obj.countOpponents(P, K); break;
			}*/
			/*case 7:
			{
				int P = ;
				int K = ;
				_expected = ;
				_received = _obj.countOpponents(P, K); break;
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
