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
#include <cassert>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 

struct AimToTen {
   int need( vector <int> marks ) {
        int N=marks.size();
		int sum=0;
		REP(i,N)sum+=marks[i];
		if(sum*10>=95*N)return 0;
        int ans=(95*N)-10*sum;
        //assert(ans%5==0);
		return ans/5;
		
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
		cout << "Testing AimToTen (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367809420;
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
		AimToTen _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int marks[] = {9, 10, 10, 9};
				_expected = 0;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
			}
			case 1:
			{
				int marks[] = {8, 9};
				_expected = 4;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
			}
			case 2:
			{
				int marks[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				               0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				               0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = 950;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
			}
			case 3:
			{
				int marks[] = {10, 10, 10, 10};
				_expected = 0;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
			}
			/*case 4:
			{
				int marks[] = ;
				_expected = ;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int marks[] = ;
				_expected = ;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int marks[] = ;
				_expected = ;
				_received = _obj.need(vector <int>(marks, marks+sizeof(marks)/sizeof(int))); break;
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
