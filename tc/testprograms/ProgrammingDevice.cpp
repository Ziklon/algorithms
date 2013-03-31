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

struct ProgrammingDevice {
   int minPackets( vector <int> offset, vector <int> size, int maxData ) {
        int ans=0;
		int n=offset.size();
		vector<pair<ll,ll> >v;
		REP(i,n)v.push_back(make_pair(offset[i],size[i]));
		sort(v.begin(),v.end());
		
		ll pos=v[0].first;
		int i=0;
		while(pos< (v[n-1].first+v[n-1].second)){
			ll  k=(v[i].first-pos+v[i].second+maxData-1)/maxData;
			ans+=(k);
			pos+=(maxData*k);
			for(;i<n;i++)if(pos<(v[i].first+v[i].second))break;
			if(i<n && pos<v[i].first)pos=v[i].first;
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
		cout << "Testing ProgrammingDevice (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356645665;
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
		ProgrammingDevice _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int offset[] = {0, 10, 20, 30};
				int size[] = {8, 5, 3, 11};
				int maxData = 6;
				_expected = 6;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}
			case 1:
			{
				int offset[] = {0, 10, 20, 30};
				int size[] = {8, 2, 3, 11};
				int maxData = 6;
				_expected = 5;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}
			case 2:
			{
				int offset[] = {15, 95};
				int size[] = {1, 20};
				int maxData = 100;
				_expected = 1;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}
			case 3:
			{
				int offset[] = {77, 7777, 777};
				int size[] = {700, 70000, 7000};
				int maxData = 1;
				_expected = 77700;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}
			case 4:
			{
				int offset[] = {0,1000000000};
				int size[] = {1000000000,1000000000};
				int maxData = 2000000000;
				_expected = 1;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}
			case 5:
			{
				int offset[] = {0,1000000000};
				int size[] = {1000000000,1000000000};
				int maxData = 1;
				_expected = 2000000000;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}
			/*case 6:
			{
				int offset[] = ;
				int size[] = ;
				int maxData = ;
				_expected = ;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}*/
			/*case 7:
			{
				int offset[] = ;
				int size[] = ;
				int maxData = ;
				_expected = ;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
			}*/
			/*case 8:
			{
				int offset[] = ;
				int size[] = ;
				int maxData = ;
				_expected = ;
				_received = _obj.minPackets(vector <int>(offset, offset+sizeof(offset)/sizeof(int)), vector <int>(size, size+sizeof(size)/sizeof(int)), maxData); break;
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
