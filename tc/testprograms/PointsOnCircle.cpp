#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

struct PointsOnCircle {
   long long count( int r ) {
       	vector<ll> S;
		for(ll i=1;i*i<=r;i++)if(r%i==0){
			S.push_back(i);
			S.push_back(r/i);
		}
		set<ll> D;
		REP(i,S.size())REP(j,S.size())D.insert(S[i]*S[j]);
		
		vector<ll> d(D.begin(),D.end());
		int d1=0,d3=0;
		REP(i,d.size()){
			if(d[i]%4==1)d1++;
			if(d[i]%4==3)d3++;
		}
		return 4LL*(d1-d3);
		
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
		cout << "Testing PointsOnCircle (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356649979;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PointsOnCircle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int r = 1;
				_expected = 4LL;
				_received = _obj.count(r); break;
			}
			case 1:
			{
				int r = 2000000000;
				_expected = 76LL;
				_received = _obj.count(r); break;
			}
			case 2:
			{
				int r = 3;
				_expected = 4LL;
				_received = _obj.count(r); break;
			}
			case 3:
			{
				int r = 1053;
				_expected = 12LL;
				_received = _obj.count(r); break;
			}
			/*case 4:
			{
				int r = ;
				_expected = LL;
				_received = _obj.count(r); break;
			}*/
			/*case 5:
			{
				int r = ;
				_expected = LL;
				_received = _obj.count(r); break;
			}*/
			/*case 6:
			{
				int r = ;
				_expected = LL;
				_received = _obj.count(r); break;
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
