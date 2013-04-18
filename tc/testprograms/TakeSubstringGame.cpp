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
bool dp[1<<20];
int digs[10];

struct TakeSubstringGame {
   int winningMove( int n ) {
       REP(i,10)dp[i]=0;
       int ans=1<<30;
       REP(i,n+1)if(i>=10){
           dp[i]=0;
           int tmp=i;
           int nd=0;
           while(tmp){
               digs[nd++]=tmp%10;
               tmp/=10; 
           }
           reverse(digs,digs+nd);
           for(int j=0;j<nd;j++){
               int num=0;
               for(int k=1;k+j<=nd;k++){
                   num=(num*10) + digs[j+k-1];
                   if(k==nd || num==0)continue;
                   if(dp[i-num]==0){
                       dp[i]=1;                        
                       if(i==n)ans=min(ans,num);
                    } 
               } 
           }           
            
       }
       if(dp[n]==0)return -1;
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
		cout << "Testing TakeSubstringGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366142510;
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
		TakeSubstringGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				_expected = -1;
				_received = _obj.winningMove(n); break;
			}
			case 1:
			{
				int n = 10;
				_expected = 1;
				_received = _obj.winningMove(n); break;
			}
			case 2:
			{
				int n = 17;
				_expected = -1;
				_received = _obj.winningMove(n); break;
			}
			
			case 3:
			{
				int n = 239;
				_expected = 9;
				_received = _obj.winningMove(n); break;
			}
			case 4:
			{
				int n = 566;
				_expected = 66;
				_received = _obj.winningMove(n); break;
			}
			case 5:
			{
				int n = 23900;
				_expected = -1;
				_received = _obj.winningMove(n); break;
			}
			case 6:
			{
				int n =1000000;
				_expected =234 ;
				_received = _obj.winningMove(n); break;
			}
			/*case 7:
			{
				int n = ;
				_expected = ;
				_received = _obj.winningMove(n); break;
			}*/
			/*case 8:
			{
				int n = ;
				_expected = ;
				_received = _obj.winningMove(n); break;
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
