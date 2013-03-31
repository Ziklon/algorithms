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

struct MirroredClock {
   string whatTimeIsIt( string time ) {
         
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
		cout << "Testing MirroredClock (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356517419;
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
		MirroredClock _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string time = "10:00";
				_expected = "02:00";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 1:
			{
				string time = "01:15";
				_expected = "10:45";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 2:
			{
				string time = "03:40";
				_expected = "08:20";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 3:
			{
				string time = "00:00";
				_expected = "00:00";
				_received = _obj.whatTimeIsIt(time); break;
			}
			case 4:
			{
				string time = "11:53";
				_expected = "00:07";
				_received = _obj.whatTimeIsIt(time); break;
			}
			/*case 5:
			{
				string time = ;
				_expected = ;
				_received = _obj.whatTimeIsIt(time); break;
			}*/
			/*case 6:
			{
				string time = ;
				_expected = ;
				_received = _obj.whatTimeIsIt(time); break;
			}*/
			/*case 7:
			{
				string time = ;
				_expected = ;
				_received = _obj.whatTimeIsIt(time); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

//END CUT HERE
