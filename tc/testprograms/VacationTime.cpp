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

struct VacationTime {
   int bestSchedule( int N, int K, vector <int> workingDays ) {
        int ans=1<<20;
		int n=workingDays.size();		
		FOR(i,1,N-K+1){
			int tmp=0;
			REP(j,n)if(workingDays[j]>=i && workingDays[j]<=(i+K-1)) tmp++;
			ans=min(ans,tmp);
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
		cout << "Testing VacationTime (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356520559;
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
		VacationTime _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 3;
				int workingDays[] = {2};
				_expected = 1;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 4;
				int K = 3;
				int workingDays[] = {3, 1, 2};
				_expected = 2;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 5;
				int K = 3;
				int workingDays[] = {4, 1};
				_expected = 1;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 9;
				int K = 2;
				int workingDays[] = {7, 4, 5, 6, 2};
				_expected = 0;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 1000;
				int K = 513;
				int workingDays[] = {808, 459, 792, 863, 715, 70, 336, 731};
				_expected = 2;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int workingDays[] = ;
				_expected = ;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int workingDays[] = ;
				_expected = ;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int workingDays[] = ;
				_expected = ;
				_received = _obj.bestSchedule(N, K, vector <int>(workingDays, workingDays+sizeof(workingDays)/sizeof(int))); break;
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
