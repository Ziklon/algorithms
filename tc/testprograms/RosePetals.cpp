#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath> 
#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm> 
using namespace std; 
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll;

struct RosePetals {
   int getScore( vector <int> dice ) {
		int ans=0;
		REP(i,dice.size()){
			if(dice[i]==3)ans+=2;
			if(dice[i]==5)ans+=4;				
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
		cout << "Testing RosePetals (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1357584210;
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
		RosePetals _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dice[] = {1, 2, 3, 2, 1};
				_expected = 2;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 1:
			{
				int dice[] = {4, 4, 5, 6, 5};
				_expected = 8;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 2:
			{
				int dice[] = {1, 2, 3, 3, 5};
				_expected = 8;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 3:
			{
				int dice[] = {3, 3, 3, 3, 3};
				_expected = 10;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			case 4:
			{
				int dice[] = {2, 2, 2, 2, 2};
				_expected = 0;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}
			/*case 5:
			{
				int dice[] = ;
				_expected = ;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int dice[] = ;
				_expected = ;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dice[] = ;
				_expected = ;
				_received = _obj.getScore(vector <int>(dice, dice+sizeof(dice)/sizeof(int))); break;
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
