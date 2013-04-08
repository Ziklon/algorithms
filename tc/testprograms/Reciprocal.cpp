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

struct Reciprocal {

    int fastExpo(int b, int m){//(10^b)%m
        if(b==0)return 1;
        int ans=fastExpo(b/2,m)%m;
        ans=(ans*ans)%m;
        if(b&1)ans=(ans*10)%m;
        return ans;
    }
    
   string digits( int x, int d, int n ) {
		string ans=string(n,'0');
		int i=0;
		int val=fastExpo(d-1,x);
		while(i<n){
            if(val/x==0)val*=10;
            int tmp=val/x;
            val%=x;
            ans[i]='0'+tmp;
            i++;
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
		cout << "Testing Reciprocal (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365144996;
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
		Reciprocal _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 7;
				int d = 2;
				int n = 4;
				_expected = "4285";
				_received = _obj.digits(x, d, n); break;
			}
			case 1:
			{
				int x = 10000;
				int d = 1;
				int n = 7;
				_expected = "0001000";
				_received = _obj.digits(x, d, n); break;
			}
			case 2:
			{
				int x = 3;
				int d = 5000;
				int n = 8;
				_expected = "33333333";
				_received = _obj.digits(x, d, n); break;
			}
			case 3:
			{
				int x = 9999;
				int d = 9;
				int n = 13;
				_expected = "0001000100010";
				_received = _obj.digits(x, d, n); break;
			}
			case 4:
			{
				int x = 7549;
				int d = 50000;
				int n = 1;
				_expected = "0";
				_received = _obj.digits(x, d, n); break;
			}
			/*case 5:
			{
				int x = ;
				int d = ;
				int n = ;
				_expected = ;
				_received = _obj.digits(x, d, n); break;
			}*/
			/*case 6:
			{
				int x = ;
				int d = ;
				int n = ;
				_expected = ;
				_received = _obj.digits(x, d, n); break;
			}*/
			/*case 7:
			{
				int x = ;
				int d = ;
				int n = ;
				_expected = ;
				_received = _obj.digits(x, d, n); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
