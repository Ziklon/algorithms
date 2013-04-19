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


int dp[55],K;
bool can[55][55];
vector<int> x,y,stairLen, sweets;

double calc(int i, int j){
    if(x[i]+stairLen[i]<=x[j]) return hypot(x[i]+stairLen[i]-x[j],y[i]-y[j]);
    if(x[j]+stairLen[j]<=x[i])return hypot(x[j]+stairLen[j]-x[i],y[j]-y[i]);
    return abs(y[j]-y[i]);
}

int go(int idx){    
    int& ref=dp[idx];
    if(ref!=-1)return ref;
    ref=0;
    vector<int> v(1,idx);
    int coll=0;
    REP(i,x.size())if(can[idx][i] && i!=idx){
        v.push_back(i);
        coll+=sweets[i];
    }
    ref=coll;
    REP(k,v.size()){
        idx=v[k];
        REP(j,x.size())if(y[j]> y[idx]){
            double dist=calc(j,idx);
            if(dist<=K)
                ref=max(ref,go(j)+coll+sweets[j]);
        }        
    }   
    return ref;
}

struct GetToTheTop {
   int collectSweets( int _K, vector <int> _sweets, vector <int> _x, vector <int> _y, vector <int> _stairLength ) {
		K=_K;		
		x=_x;y=_y;
		sweets=_sweets;
		stairLen=_stairLength;
		x.push_back(0);
		y.push_back(0);
		sweets.push_back(0);
		stairLen.push_back(100000);
		memset(dp,-1,sizeof dp);
		int N=x.size();
		REP(i,N)REP(j,N){
            if(y[i]==y[j]){
                int len=min(abs(x[j]+stairLen[j]-x[i]), abs(x[i]+stairLen[i]-x[j]));
                if(len<=K)
                    can[i][j]=1;
            }
		}
		REP(i,N)can[i][i]=1;		
		REP(k,N)REP(i,N)REP(j,N){
            can[i][j]|=(can[i][k]&&can[k][j]);
        }		
		return go(x.size()-1);
		
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
		cout << "Testing GetToTheTop (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366338685;
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
		GetToTheTop _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 2;
				int sweets[] = {1, 2, 3, 4, 3, 5};
				int x[] = {1, 1, 1, 4, 5, 5};
				int y[] = {1, 3, 4, 1, 2, 3};
				int stairLength[] = {2, 1, 1, 2, 1, 1};
				_expected = 13;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 1:
			{
				int K = 4;
				int sweets[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4};
				int x[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10};
				int y[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9};
				int stairLength[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2};
				_expected = 47;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 2:
			{
				int K = 10;
				int sweets[] = {1, 3, 5, 7};
				int x[] = {1, 6, 2, 8};
				int y[] = {2, 4, 1, 2};
				int stairLength[] = {4, 1, 7, 4};
				_expected = 16;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 3:
			{
				int K = 3;
				int sweets[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1};
				int x[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20};
				int y[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11};
				int stairLength[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 129;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 4:
			{
				int K = 10;
				int sweets[] = {0, 10, 11, 2, 0};
				int x[] = {1, 26, 29, 22, 3};
				int y[] = {1, 83, 88, 22, 5};
				int stairLength[] = {11, 1, 23, 15, 8};
				_expected = 0;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 5:
			{
				int K = 5;
				int sweets[] = {2, 0, 5};
				int x[] = {1, 8, 9};
				int y[] = {6, 6, 1};
				int stairLength[] = {3, 6, 3};
				_expected = 7;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 6:
			{
				int K = 2;
				int sweets[] = {2, 9, 9, 1, 9, 9, 8};
				int x[] = {10, 8, 6, 6, 8, 7, 3};
				int y[] = {6, 7, 5, 4, 5, 2, 5};
				int stairLength[] = {1, 1, 1, 1, 1, 1, 1};
				_expected = 47;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			/*case 7:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
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
