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
struct DivisibleByDigits {
   long long getContinuation( int n ) {
		long long ans=0;
		ll aux=n;
		vector<int> v(10,0);
		while(aux){
			v[aux%10]=1;
			aux/=10;
		}	
		queue<ll> Q;
		Q.push(n);	
		while(!Q.empty()){			
			ll tmp=Q.front();Q.pop();
			bool ok=1;
			REP(i,10)if(i>0 && v[i]>0 && (tmp%i)!=0)ok=0;
			if(ok)return tmp;
			REP(i,10)Q.push((tmp*10)+i);			
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
		cout << "Testing DivisibleByDigits (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1357593052;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DivisibleByDigits _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 13;
				_expected = 132LL;
				_received = _obj.getContinuation(n); break;
			}
			case 1:
			{
				int n = 648;
				_expected = 648LL;
				_received = _obj.getContinuation(n); break;
			}
			case 2:
			{
				int n = 566;
				_expected = 56610LL;
				_received = _obj.getContinuation(n); break;
			}
			case 3:
			{
				int n = 1000000000;
				_expected = 1000000000LL;
				_received = _obj.getContinuation(n); break;
			}
			case 4:
			{
				int n = 987654321;
				_expected = 987654321360LL;
				_received = _obj.getContinuation(n); break;
			}
			case 5:
			{
				int n = 83;
				_expected = 8304LL;
				_received = _obj.getContinuation(n); break;
			}
			case 6:
			{
				int n =191 ;
				_expected = 1917LL;
				_received = _obj.getContinuation(n); break;
			}
			/*case 7:
			{
				int n = ;
				_expected = LL;
				_received = _obj.getContinuation(n); break;
			}*/
			/*case 8:
			{
				int n = ;
				_expected = LL;
				_received = _obj.getContinuation(n); break;
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
