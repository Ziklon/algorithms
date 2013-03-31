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

struct PowerPlants {
   int minCost( vector <string> connectionCost, string plantList, int numPlants ) {
      return 0;
   }
};
//BEGIN CUT HERE
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
		cout << "Testing PowerPlants (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356516931;
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
		PowerPlants _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string connectionCost[] = {"024",
				                           "203",
				                           "430"};
				string plantList = "YNN";
				int numPlants = 3;
				_expected = 5;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 1:
			{
				string connectionCost[] = {"0AB",
				                           "A0C",
				                           "CD0"};
				string plantList = "YNN";
				int numPlants = 3;
				_expected = 21;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 2:
			{
				string connectionCost[] = {"1ABCD",
				                           "35HF8",
				                           "FDM31",
				                           "AME93",
				                           "01390"};
				string plantList = "NYNNN";
				int numPlants = 5;
				_expected = 14;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 3:
			{
				string connectionCost[] = {"012",
				                           "123",
				                           "234"};
				string plantList = "NNY";
				int numPlants = 2;
				_expected = 2;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 4:
			{
				string connectionCost[] = {"1309328",
				                           "DS2389U",
				                           "92EJFAN",
				                           "928FJNS",
				                           "FJS0DJF",
				                           "9FWJW0E",
				                           "23JFNFS"};
				string plantList = "YYNYYNY";
				int numPlants = 4;
				_expected = 0;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			case 5:
			{
				string connectionCost[] = {"01","20"};
				string plantList = "YN";
				int numPlants = 2;
				_expected = 1;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}
			/*case 6:
			{
				string connectionCost[] = ;
				string plantList = ;
				int numPlants = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}*/
			/*case 7:
			{
				string connectionCost[] = ;
				string plantList = ;
				int numPlants = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
			}*/
			/*case 8:
			{
				string connectionCost[] = ;
				string plantList = ;
				int numPlants = ;
				_expected = ;
				_received = _obj.minCost(vector <string>(connectionCost, connectionCost+sizeof(connectionCost)/sizeof(string)), plantList, numPlants); break;
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

//END CUT HERE
