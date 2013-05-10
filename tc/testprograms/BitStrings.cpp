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
typedef long long ll; 
int B[55];
struct BitStrings {
   int maxStrings( vector <string> list, int numZeroes, int numOnes ) {
		int N=list.size();
		REP(i,N)B[i]=count(list[i].begin(),list[i].end(),'1');
		int ans=0;
		REP(mask,1<<N){
            int ones=0,zeros=0;
            REP(i,N)if(mask&(1<<i)){
                ones+=B[i];
                zeros+=(list[i].size()-B[i]);
            }
            if( ones<=numOnes && zeros<=numZeroes)
                  ans=max(ans,__builtin_popcount(mask));  
            
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
		cout << "Testing BitStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367641975;
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
		BitStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string list[] = {"1", "00", "100"};
				int numZeroes = 3;
				int numOnes = 1;
				_expected = 2;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
			}
			case 1:
			{
				string list[] = {"00", "110", "101"};
				int numZeroes = 2;
				int numOnes = 4;
				_expected = 2;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
			}
			case 2:
			{
				string list[] = {"111", "01", "11", "10", "101"};
				int numZeroes = 3;
				int numOnes = 9;
				_expected = 5;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
			}
			case 3:
			{
				string list[] = {"10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010",
				                "10101010101010101010101010101010101010101010101010"};
				int numZeroes = 500;
				int numOnes = 500;
				_expected = 20;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
			}
			/*case 4:
			{
				string list[] = ;
				int numZeroes = ;
				int numOnes = ;
				_expected = ;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
			}*/
			/*case 5:
			{
				string list[] = ;
				int numZeroes = ;
				int numOnes = ;
				_expected = ;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
			}*/
			/*case 6:
			{
				string list[] = ;
				int numZeroes = ;
				int numOnes = ;
				_expected = ;
				_received = _obj.maxStrings(vector <string>(list, list+sizeof(list)/sizeof(string)), numZeroes, numOnes); break;
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
