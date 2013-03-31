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

struct TournamentsAmbiguityNumber {
   int scrutinizeTable( vector <string> table ) {
	   int ans=0;
	   int n=table.size();
	   REP(i,n)REP(j,n)REP(k,n)
		   if(table[i][j]=='1' && table[j][k]=='1' && table[k][i]=='1')ans++;
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
		cout << "Testing TournamentsAmbiguityNumber (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356649469;
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
		TournamentsAmbiguityNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string table[] = {"-10",
				                  "0-1",
				                  "10-"};
				_expected = 3;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 1:
			{
				string table[] = {"----",
				                  "----",
				                  "----",
				                  "----"};
				_expected = 0;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 2:
			{
				string table[] = {"-1",
				                  "0-"};
				_expected = 0;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			case 3:
			{
				string table[] = {"--1-10-1---1--1-00",
				                  "--0110000--0---10-",
				                  "01--00000100-00011",
				                  "-0---0010-11110100",
				                  "001--01-00-0001-1-",
				                  "11111--100--1-1-01",
				                  "-1110--00110-11-01",
				                  "0110-01--100110-10",
				                  "-111111---01--0-01",
				                  "--0-1100----10011-",
				                  "--10--011--1--101-",
				                  "01101-110-0--1-0-1",
				                  "---010-0-0---00-11",
				                  "--101-00-1-01-0-0-",
				                  "0-110001110-11-110",
				                  "-010-----011--0--0",
				                  "11010110100-010--0",
				                  "1-01-0010--00-111-"};
				_expected = 198;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}
			/*case 4:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string table[] = ;
				_expected = ;
				_received = _obj.scrutinizeTable(vector <string>(table, table+sizeof(table)/sizeof(string))); break;
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
