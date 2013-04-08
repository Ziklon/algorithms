#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;
int dp[55][55];
string cad;
int n;
int go(int x, int y){
	if(x>=y)return 0;
	int& ref=dp[x][y];	
	if(ref!=-1)return ref;
	ref=0;
	for(int i=x;i<=y;i++){
		for(int j=i+1;j<=y;j++){
			if(cad[i]==cad[j]){
				int res=go(i+1,j-1)+go(j+1,y-1)+1;
				ref=max(ref,res);
			}
		}
	}
	return ref;
}

struct PenguinPals {
   int findMaximumMatching( string colors ) {
		
		n=colors.size();
		cad=colors;
		memset(dp,-1,sizeof dp);
		
		int ans=go(0,n-1);
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
		cout << "Testing PenguinPals (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358024327;
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
		PenguinPals _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string colors = "RRBRBRBB";
				_expected = 3;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 1:
			{
				string colors = "RRRR";
				_expected = 2;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 2:
			{
				string colors = "BBBBB";
				_expected = 2;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 3:
			{
				string colors = "RBRBRBRBR";
				_expected = 4;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 4:
			{
				string colors = "RRRBRBRBRBRB";
				_expected = 5;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 5:
			{
				string colors = "R";
				_expected = 0;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 6:
			{
				string colors = "RBRRBBRB";
				_expected = 3;
				_received = _obj.findMaximumMatching(colors); break;
			}
			case 7:
			{
				string colors = "RBRBBRBRB";
				_expected = 4;
				_received = _obj.findMaximumMatching(colors); break;
			}
			/*case 8:
			{
				string colors = ;
				_expected = ;
				_received = _obj.findMaximumMatching(colors); break;
			}*/
			/*case 9:
			{
				string colors = ;
				_expected = ;
				_received = _obj.findMaximumMatching(colors); break;
			}*/
			/*case 10:
			{
				string colors = ;
				_expected = ;
				_received = _obj.findMaximumMatching(colors); break;
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
