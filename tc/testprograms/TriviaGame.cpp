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
int dp[50][10001],tokenNed;
vector<int> points,bonus;
int go(int idx, int bon){
    if(idx>=points.size())return 0;
    int& ref=dp[idx][bon];
    if(ref!=-1)return ref;
    ref=go(idx+1,bon)-points[idx];//wrong answer
    if(bon+1==tokenNed)
        ref=max(ref,go(idx+1,0)+points[idx]+bonus[idx]);
    else 
        ref=max(ref,go(idx+1,bon+1)+points[idx]);
    return ref;
}

struct TriviaGame {
   int maximumScore( vector <int> _points, int tokensNeeded, vector <int> _bonuses ) {
        points=_points;
        bonus=_bonuses;
        tokenNed=tokensNeeded;
        memset(dp,-1,sizeof dp);
        return go(0,0);		
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
		cout << "Testing TriviaGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366094807;
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
		TriviaGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {1, 2, 3, 4, 5, 6};
				int tokensNeeded = 3;
				int bonuses[] = {4, 4, 4, 4, 4, 4};
				_expected = 29;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
			}
			case 1:
			{
				int points[] = {1, 2, 3, 4, 5, 6};
				int tokensNeeded = 3;
				int bonuses[] = {1, 1, 1, 20, 1, 1};
				_expected = 39;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
			}
			case 2:
			{
				int points[] = {150, 20, 30, 40, 50};
				int tokensNeeded = 3;
				int bonuses[] = {0, 0, 0, 250, 0};
				_expected = 500;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
			}
			case 3:
			{
				int points[] = {500, 500, 500, 0, 500};
				int tokensNeeded = 3;
				int bonuses[] = {0, 0, 0, 500, 0};
				_expected = 2000;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
			}
			/*case 4:
			{
				int points[] = ;
				int tokensNeeded = ;
				int bonuses[] = ;
				_expected = ;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int points[] = ;
				int tokensNeeded = ;
				int bonuses[] = ;
				_expected = ;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int points[] = ;
				int tokensNeeded = ;
				int bonuses[] = ;
				_expected = ;
				_received = _obj.maximumScore(vector <int>(points, points+sizeof(points)/sizeof(int)), tokensNeeded, vector <int>(bonuses, bonuses+sizeof(bonuses)/sizeof(int))); break;
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
