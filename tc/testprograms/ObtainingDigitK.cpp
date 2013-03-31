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

string sum(string a, string b){
	string ans;
	int res=b[0]-'0';
	int n=a.size();
	for(int i=0;i<a.size();i++){
		int tmp=a[n-i-1]-'0'+res;
		res=0;
		if(tmp>=10)res=1;
		tmp%=10;
		ans=string(1,'0'+tmp)+ans;
	}
	if(res)ans=string(1,'1')+ans;
	return ans;
}
struct ObtainingDigitK {
   int minNumberToAdd( string originalNumber, int k ) {
        int ans=0;
		for(int i=0;i<10;i++){
			string tmp=sum(originalNumber,string(1,'0'+i));
			if(tmp.find(string(1,'0'+k))!=-1){
				return i;
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
		cout << "Testing ObtainingDigitK (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356643989;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ObtainingDigitK _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string originalNumber = "153";
				int k = 7;
				_expected = 4;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			case 1:
			{
				string originalNumber = "158";
				int k = 7;
				_expected = 9;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			case 2:
			{
				string originalNumber = "7853192";
				int k = 2;
				_expected = 0;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			case 3:
			{
				string originalNumber = "99999999999999999999999999999999999999999999999";
				int k = 0;
				_expected = 1;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}
			/*case 4:
			{
				string originalNumber = ;
				int k = ;
				_expected = ;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}*/
			/*case 5:
			{
				string originalNumber = ;
				int k = ;
				_expected = ;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
			}*/
			/*case 6:
			{
				string originalNumber = ;
				int k = ;
				_expected = ;
				_received = _obj.minNumberToAdd(originalNumber, k); break;
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
