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

struct PenguinSledding {
   long long countDesigns( int num, vector <int> va, vector <int> vb ) {
		vector<ll> sets;
		ll ans=va.size()+1;		
		for(int i=0;i<va.size();i++){
			ll tmp=1LL<<i;
			for(int j=i+1;j<vb.size();j++){				
				if((va[i]==vb[j]) || (va[i]==va[j]) ||
					(vb[i]==vb[j]) || vb[i]==va[j]){
					ans++;
				}
			}c			
		}
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
		cout << "Testing PenguinSledding (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358010601;
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
		PenguinSledding _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numCheckpoints = 2;
				int checkpoint1[] = {1};
				int checkpoint2[] = {2};
				_expected = 2LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}
			case 1:
			{
				int numCheckpoints = 4;
				int checkpoint1[] = {1,2,3};
				int checkpoint2[] = {2,3,4};
				_expected = 6LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}
			case 2:
			{
				int numCheckpoints = 6;
				int checkpoint1[] = {1,3,6};
				int checkpoint2[] = {2,4,4};
				_expected = 5LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}
			case 3:
			{
				int numCheckpoints = 50;
				int checkpoint1[] = {40, 40, 40, 40, 40, 40, 40, 40, 
				                     40, 40, 40, 40, 50, 40, 40, 40, 
				                     23, 4, 24, 40, 22, 40, 8, 40, 40,
				                     40, 34, 21, 40, 40, 38, 40, 40, 
				                     40, 40, 40, 28, 40, 40, 40, 40, 
				                     46, 13, 40, 40, 40, 47, 40, 40};
				int checkpoint2[] = {45, 42, 20, 48, 12, 32, 25, 10, 
				                     26, 39, 16, 2, 19, 43, 37, 17, 
				                     19, 19, 19, 18, 19, 27, 19, 29, 
				                     11, 36, 19, 19, 1, 41, 19, 35, 
				                     14, 33, 49, 3, 19, 7, 5, 19, 31, 
				                     19, 19, 6, 9, 15, 19, 44, 30};
				_expected = 68719493118LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}
			case 4:
			{
				int numCheckpoints = 36;
				int checkpoint1[] = {13, 24, 24, 20, 31, 16, 10, 36, 34, 32, 
				                     28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19, 
				                     21, 8, 1, 26, 27, 25, 15, 22, 30, 30, 
				                     6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18, 
				                     13, 14, 17, 35, 3};
				int checkpoint2[] = {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
				                     2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
				                     4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
				                     21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
				                     8, 36, 26, 23};
				_expected = 162LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int numCheckpoints = ;
				int checkpoint1[] = ;
				int checkpoint2[] = ;
				_expected = LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int numCheckpoints = ;
				int checkpoint1[] = ;
				int checkpoint2[] = ;
				_expected = LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int numCheckpoints = ;
				int checkpoint1[] = ;
				int checkpoint2[] = ;
				_expected = LL;
				_received = _obj.countDesigns(numCheckpoints, vector <int>(checkpoint1, checkpoint1+sizeof(checkpoint1)/sizeof(int)), vector <int>(checkpoint2, checkpoint2+sizeof(checkpoint2)/sizeof(int))); break;
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
