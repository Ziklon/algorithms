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

struct EllysCoprimesDiv2 {
   int getCount( vector <int> numbers ) {
		
		int ans=0;		
		sort(numbers.begin(),numbers.end()); 
		
		REP(i,numbers.size()-1){		            
           int a=numbers[i];
           int b=numbers[i+1];
           int c=__gcd(a,b);
           if(c==1)continue;
           bool ok=0;
           for(int j=a+1;j<b;j++){
                if(__gcd(a,j)==1 && __gcd(b,j)==1)ok=1;
           }
           if(ok)ans+=1;
           else ans+=2;
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
		cout << "Testing EllysCoprimesDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367078731;
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
		EllysCoprimesDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {2200, 42, 2184, 17};
				_expected = 3;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 1:
			{
				int numbers[] = {13, 1, 6, 20, 33};
				_expected = 0;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 2:
			{
				int numbers[] = {7, 42};
				_expected = 1;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 3:
			{
				int numbers[] = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
				                 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
				                 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
				                 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666};
				_expected = 15;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			/*case 4:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
