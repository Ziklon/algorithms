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
int dp[1<<20];


struct Truckloads {
   int numTrucks( int numCrates, int loadSize ) {
   
        REP(i,loadSize+1)dp[i]=1;
        REP(i,numCrates+1)if(i>loadSize)dp[i]=dp[(i/2)]+dp[i-(i/2)];
        return dp[numCrates];
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
		cout << "Testing Truckloads (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367082465;
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
		Truckloads _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numCrates = 14;
				int loadSize = 3;
				_expected = 6;
				_received = _obj.numTrucks(numCrates, loadSize); break;
			}
			case 1:
			{
				int numCrates = 15;
				int loadSize = 1;
				_expected = 15;
				_received = _obj.numTrucks(numCrates, loadSize); break;
			}
			case 2:
			{
				int numCrates = 1024;
				int loadSize = 5;
				_expected = 256;
				_received = _obj.numTrucks(numCrates, loadSize); break;
			}
			case 3:
			{
				int numCrates =10000 ;
				int loadSize = 2;
				_expected = 100;
				_received = _obj.numTrucks(numCrates, loadSize); break;
			}
			/*case 4:
			{
				int numCrates = ;
				int loadSize = ;
				_expected = ;
				_received = _obj.numTrucks(numCrates, loadSize); break;
			}*/
			/*case 5:
			{
				int numCrates = ;
				int loadSize = ;
				_expected = ;
				_received = _obj.numTrucks(numCrates, loadSize); break;
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
