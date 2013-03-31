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
#include <sstream> 
using namespace std; 
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;

struct TheSquareRootDilemma {
   int countPairs( int N, int M ) {
		
		int ans=0;
		set<pair<int,int> >S;
		for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
			int aa=sqrt(i*j);
			if(aa*aa==(i*j)){
				S.insert(make_pair(i,j));
			}
		}
		
		
		for(ll i=1;i*i<=100000000000LL;i++){
			int ii=i*i;	
			for(int j=1;j*j<=ii;j++){
				if(ii%j==0){
					int b=ii/j;
					int mini=min(b,j);
					int maxi=max(b,j);
					if(mini<=M && maxi<=N)
						ans++;
				}
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
		cout << "Testing TheSquareRootDilemma (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358771427;
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
		TheSquareRootDilemma _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				_expected = 2;
				_received = _obj.countPairs(N, M); break;
			}
			case 1:
			{
				int N = 10;
				int M = 1;
				_expected = 3;
				_received = _obj.countPairs(N, M); break;
			}
			case 2:
			{
				int N = 3;
				int M = 8;
				_expected = 5;
				_received = _obj.countPairs(N, M); break;
			}
			
			case 3:
			{
				int N = 100;
				int M = 100;
				_expected = 310;
				_received = _obj.countPairs(N, M); break;
			}
			/*case 4:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
			}*/
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
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
