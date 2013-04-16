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


int func(int a, int n){
    int ans=0;
    for(int i=1;i<=a;i++){
        ans+=a/i;
        if(i<=a)ans--;
        int tmp=a;        
        for(int j=0;j<n;j++)tmp/=i;
        ans-=tmp;
        if(i==1)ans++;
    }
    return ans;    
}

struct ProperDivisors {
   int analyzeInterval( int a, int b, int n ) {
        cout<<func(8,2)<<endl;
        return func(a+b,n)-func(a-1,n);
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
		cout << "Testing ProperDivisors (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366089203;
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
		ProperDivisors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 32;
				int b = 1;
				int n = 3;
				_expected = 5;
				_received = _obj.analyzeInterval(a, b, n); break;
			}
			case 1:
			{
				int a = 1;
				int b = 12;
				int n = 2;
				_expected = 8;
				_received = _obj.analyzeInterval(a, b, n); break;
			}
			case 2:
			{
				int a = 1000000;
				int b = 10000000;
				int n = 10;
				_expected = 146066338;
				_received = _obj.analyzeInterval(a, b, n); break;
			}
			/*case 3:
			{
				int a = ;
				int b = ;
				int n = ;
				_expected = ;
				_received = _obj.analyzeInterval(a, b, n); break;
			}*/
			/*case 4:
			{
				int a = ;
				int b = ;
				int n = ;
				_expected = ;
				_received = _obj.analyzeInterval(a, b, n); break;
			}*/
			/*case 5:
			{
				int a = ;
				int b = ;
				int n = ;
				_expected = ;
				_received = _obj.analyzeInterval(a, b, n); break;
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
