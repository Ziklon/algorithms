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
#include <cstdio>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 



struct SwappingDigits {
   string minNumber( string num ) {
		string ans=num;
		int N=num.size();
		REP(i,N)REP(j,N)if(j>i){
            swap(num[i],num[j]);
            if(num[0]>'0')ans=min(ans,num);
            swap(num[i],num[j]);
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
		cout << "Testing SwappingDigits (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1371689271;
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
		SwappingDigits _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string num = "596";
				_expected = "569";
				_received = _obj.minNumber(num); break;
			}
			case 1:
			{
				string num = "93561";
				_expected = "13569";
				_received = _obj.minNumber(num); break;
			}
			case 2:
			{
				string num = "5491727514";
				_expected = "1491727554";
				_received = _obj.minNumber(num); break;
			}
			case 3:
			{
				string num = "10234";
				_expected = "10234";
				_received = _obj.minNumber(num); break;
			}
			case 4:
			{
				string num = "93218910471211292416";
				_expected = "13218910471211292496";
				_received = _obj.minNumber(num); break;
			}
			/*case 5:
			{
				string num = ;
				_expected = ;
				_received = _obj.minNumber(num); break;
			}*/
			/*case 6:
			{
				string num = ;
				_expected = ;
				_received = _obj.minNumber(num); break;
			}*/
			/*case 7:
			{
				string num = ;
				_expected = ;
				_received = _obj.minNumber(num); break;
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
