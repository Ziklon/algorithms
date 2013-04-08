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
using namespace std; 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
typedef long long ll; 

struct MedianOfNumbers {
   int findMedian( vector <int> numbers ) {
        sort(numbers.begin(),numbers.end());
        int N=numbers.size();
        if(N%2)return numbers[N/2];
        return -1;
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
		cout << "Testing MedianOfNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365129344;
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
		MedianOfNumbers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {1, 4, 2, 5, 7};
				_expected = 4;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 1:
			{
				int numbers[] = {1, 5, 8, 3};
				_expected = -1;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 2:
			{
				int numbers[] = {7};
				_expected = 7;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 3:
			{
				int numbers[] = {7, 12};
				_expected = -1;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 4:
			{
				int numbers[] = {66, 53, 47, 86, 18, 21, 97, 92, 15};
				_expected = 53;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			case 5:
			{
				int numbers[] = {32, 54, 27, 4, 69, 96, 73, 1, 100, 15, 21};
				_expected = 32;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}
			/*case 6:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int numbers[] = ;
				_expected = ;
				_received = _obj.findMedian(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int))); break;
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
