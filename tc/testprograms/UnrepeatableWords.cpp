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
int N,K,A;
int a[55];
bool check(int x) { 
    for (int len = 1; len <= (x + 1) / K; len++) { 
      bool sw = false; 
      for (int j = x - len; j > x - len * K; j--) { 
        if (a[j] != a[j + len]) { 
          sw = true; 
          break; 
        } 
      } 
      if (sw == false) return true; 
    } 
    return false; 
} 

bool dfs(int x){
    if(x>=N)return 1;
    REP(i,A){
        a[x]=i;
        if(check(x))continue;
        if(dfs(x+1))return 1;    
    }
    return 0;
    
}

struct UnrepeatableWords {
   string getWord( int k, int n, int allowed ) {
       N=n;A=allowed;
       K=k;
       string ans;
       if(!dfs(0))return ans;
       REP(i,n)ans+=string(1,'A'+a[i]);
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
		cout << "Testing UnrepeatableWords (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366687707;
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
		UnrepeatableWords _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 3;
				int n = 5;
				int allowed = 2;
				_expected = "AABAA";
				_received = _obj.getWord(k, n, allowed); break;
			}
			case 1:
			{
				int k = 3;
				int n = 5;
				int allowed = 1;
				_expected = "";
				_received = _obj.getWord(k, n, allowed); break;
			}
			case 2:
			{
				int k = 3;
				int n = 10;
				int allowed = 2;
				_expected = "AABAABABAA";
				_received = _obj.getWord(k, n, allowed); break;
			}
			case 3:
			{
				int k = 3;
				int n = 50;
				int allowed = 2;
				_expected = "AABAABABAABAABBAABAABABAABAABBAABAABABAABABBAABAAB";
				_received = _obj.getWord(k, n, allowed); break;
			}
			/*case 4:
			{
				int k = ;
				int n = ;
				int allowed = ;
				_expected = ;
				_received = _obj.getWord(k, n, allowed); break;
			}*/
			/*case 5:
			{
				int k = ;
				int n = ;
				int allowed = ;
				_expected = ;
				_received = _obj.getWord(k, n, allowed); break;
			}*/
			/*case 6:
			{
				int k = ;
				int n = ;
				int allowed = ;
				_expected = ;
				_received = _obj.getWord(k, n, allowed); break;
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

// END CUT HERE
