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
#define MOD 1000000007LL

ll modpow(ll a, ll n){
    ll ans=1;
    while(n){
       if(n&1)ans=(ans*a)%MOD;
       n>>=1;
       a=(a*a)%MOD;
    }
    return ans;
}
ll binomial(int a, int b){
   ll n1=1;
   ll n2=1;
   REP(i,b)n1=(n1*(a-i))%MOD;
   REP(i,b+1)if(i>=1)n2=(n2*i)%MOD;
   return (n1*modpow(n2,MOD-2))%MOD;    
}


struct SuperSum {
   int calculate( int k, int n ) {
		return (int)binomial(n+k,k+1);
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
		cout << "Testing SuperSum (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366939614;
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
		SuperSum _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				int n = 3;
				_expected = 6;
				_received = _obj.calculate(k, n); break;
			}
			case 1:
			{
				int k = 2;
				int n = 3;
				_expected = 10;
				_received = _obj.calculate(k, n); break;
			}
			case 2:
			{
				int k = 4;
				int n = 10;
				_expected = 2002;
				_received = _obj.calculate(k, n); break;
			}
			case 3:
			{
				int k = 10;
				int n = 35;
				_expected = 150595840;
				_received = _obj.calculate(k, n); break;
			}
			/*case 4:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
			}*/
			/*case 5:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
			}*/
			/*case 6:
			{
				int k = ;
				int n = ;
				_expected = ;
				_received = _obj.calculate(k, n); break;
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
