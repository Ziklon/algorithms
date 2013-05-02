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
string vow="aeiuoy";
struct EllysNewNickname {
   int getLength( string nickname ) {
		int ans=0;
		REP(i,nickname.size()){
            if(vow.find(nickname[i])==-1)ans++;
            else{
                while(i<nickname.size() && vow.find(nickname[i])!=-1)i++;
                ans+=1;
                i--;
            }
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
		cout << "Testing EllysNewNickname (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367075498;
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
		EllysNewNickname _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string nickname = "tourist";
				_expected = 6;
				_received = _obj.getLength(nickname); break;
			}
			case 1:
			{
				string nickname = "eagaeoppooaaa";
				_expected = 6;
				_received = _obj.getLength(nickname); break;
			}
			case 2:
			{
				string nickname = "esprit";
				_expected = 6;
				_received = _obj.getLength(nickname); break;
			}
			case 3:
			{
				string nickname = "ayayayayayaya";
				_expected = 1;
				_received = _obj.getLength(nickname); break;
			}
			case 4:
			{
				string nickname = "wuuut";
				_expected = 3;
				_received = _obj.getLength(nickname); break;
			}
			case 5:
			{
				string nickname = "naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan";
				_expected = 16;
				_received = _obj.getLength(nickname); break;
			}
			/*case 6:
			{
				string nickname = ;
				_expected = ;
				_received = _obj.getLength(nickname); break;
			}*/
			/*case 7:
			{
				string nickname = ;
				_expected = ;
				_received = _obj.getLength(nickname); break;
			}*/
			/*case 8:
			{
				string nickname = ;
				_expected = ;
				_received = _obj.getLength(nickname); break;
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
