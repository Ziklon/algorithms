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

struct ANDEquation {
   int restoreY( vector <int> A ) {
        int N=A.size();
		REP(i,N){
            int val=(1<<30)-1;
            REP(j,N)
                if(j!=i)val&=A[j];
            if(val==A[i])return A[i];            
		}
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
		cout << "Testing ANDEquation (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1372825451;
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
		ANDEquation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1, 3, 5};
				_expected = 1;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {31, 7};
				_expected = -1;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {31, 7, 7};
				_expected = 7;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,
				           0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
				_expected = 0;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,
				           191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,
				           191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,
				           191411,191411,191411};
				_expected = 191411;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
				_expected = -1;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {2, 3, 7, 19};
				_expected = -1;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.restoreY(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
