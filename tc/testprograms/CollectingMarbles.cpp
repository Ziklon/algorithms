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
int dp[11][21][1<<13],cap;
vector<int> v;

int go(int b, int cp, int mask){
    
    int& ref=dp[b][cp][mask];
    if(ref!=-1)return ref;
    ref=0;
    bool can=0;
    int falt=0;
    REP(i,v.size()){
        if(mask&(1<<i))continue;
        if(cp>=v[i]){
          ref=max(ref,1+go(b,cp-v[i],mask|(1<<i))); 
          can=1;
        }
        falt++;
    }
    if(can==0 && b && falt>0 )ref=max(ref,go(b-1,cap,mask));
    return ref;
    
}

struct CollectingMarbles {
   int mostMarbles( vector <int> marblesWeights, int bagCapacity, int numberOfBags ) {
		cap=bagCapacity;
		v=marblesWeights;
		memset(dp,-1,sizeof dp);
		return go(numberOfBags-1,bagCapacity,0);
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
		cout << "Testing CollectingMarbles (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366097091;
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
		CollectingMarbles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int marblesWeights[] = { 2, 2, 2, 2, 2 };
				int bagCapacity = 5;
				int numberOfBags = 2;
				_expected = 4;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
			}
			case 1:
			{
				int marblesWeights[] = { 1, 3, 5, 2, 4 };
				int bagCapacity = 5;
				int numberOfBags = 2;
				_expected = 4;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
			}
			case 2:
			{
				int marblesWeights[] = { 7, 6, 6, 5 };
				int bagCapacity = 12;
				int numberOfBags = 2;
				_expected = 4;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
			}
			case 3:
			{
				int marblesWeights[] = { 2, 2, 2 };
				int bagCapacity = 1;
				int numberOfBags = 10;
				_expected = 0;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
			}
			case 4:
			{
				int marblesWeights[] = {20,20,20};
				int bagCapacity = 3;
				int numberOfBags = 3;
				_expected = 0;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
			}
			/*case 5:
			{
				int marblesWeights[] = ;
				int bagCapacity = ;
				int numberOfBags = ;
				_expected = ;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
			}*/
			/*case 6:
			{
				int marblesWeights[] = ;
				int bagCapacity = ;
				int numberOfBags = ;
				_expected = ;
				_received = _obj.mostMarbles(vector <int>(marblesWeights, marblesWeights+sizeof(marblesWeights)/sizeof(int)), bagCapacity, numberOfBags); break;
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
