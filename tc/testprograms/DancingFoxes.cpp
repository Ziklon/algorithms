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
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define INF 1<<20
typedef long long ll; 
int D[51][51],N;
struct DancingFoxes {
   int minimalDays( vector <string> friendship ) {
		N=friendship.size();
		REP(i,N)REP(j,N)D[i][j]=(i==j)?0:INF;
		REP(i,N)REP(j,N)if(friendship[i][j]=='Y')D[i][j]=1;		
		REP(k,N)REP(i,N)REP(j,N)D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
		int d=D[0][1],ans=0;
		if(d>=INF)return -1;
		while(d>1){
            d-=(d+1)/3;
            ans++;            
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
		cout << "Testing DancingFoxes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1368337555;
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
		DancingFoxes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string friendship[] = {"NNY",
				                       "NNY",
				                       "YYN"};
				_expected = 1;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}
			case 1:
			{
				string friendship[] = {"NNNNN",
				                       "NNYYY",
				                       "NYNYY",
				                       "NYYNY",
				                       "NYYYN"};
				_expected = -1;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}
			case 2:
			{
				string friendship[] = {"NNYYNN",
				                       "NNNNYY",
				                       "YNNNYN",
				                       "YNNNNY",
				                       "NYYNNN",
				                       "NYNYNN"};
				_expected = 2;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}
			case 3:
			{
				string friendship[] = {"NNYNNNNYN",
				                       "NNNNYNYNN",
				                       "YNNYNYNNN",
				                       "NNYNYNYYN",
				                       "NYNYNNNNY",
				                       "NNYNNNYNN",
				                       "NYNYNYNNN",
				                       "YNNYNNNNY",
				                       "NNNNYNNYN"};
				_expected = 3;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}
			case 4:
			{
				string friendship[] = {"NY",
				                       "YN"};
				_expected = 0;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}
			/*case 5:
			{
				string friendship[] = ;
				_expected = ;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string friendship[] = ;
				_expected = ;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string friendship[] = ;
				_expected = ;
				_received = _obj.minimalDays(vector <string>(friendship, friendship+sizeof(friendship)/sizeof(string))); break;
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
