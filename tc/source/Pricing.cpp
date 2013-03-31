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
#define INF 1<<20
int dp[55][5];
vector<int> v;

int go(int index, int group){
	if(group>4)return -INF;
	if(index>=v.size())return 0;
	int& ref=dp[index][group];
	if(ref!=-1)return ref;
	ref=go(index+1,group);	
	int sum=0;
	for(int i=index;i<v.size();i++){
		sum+=v[index];
		ref=max(ref,sum+go(i+1,group+1));	
	}	
	return ref;
	
}

struct Pricing {
   int maxSales( vector <int> price ) {
		int ans=0;
		sort(price.begin(),price.end());
		v=price;
		memset(dp,-1,sizeof dp);
		
		return go(0,0);	
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
		cout << "Testing Pricing (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358732755;
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
		Pricing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int price[] = {9,1,5,5,5,5,4,8,80};
				_expected = 120;
				_received = _obj.maxSales(vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 1:
			{
				int price[] = {17,50,2};
				_expected = 69;
				_received = _obj.maxSales(vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			case 2:
			{
				int price[] = {130,110,90,13,6,5,4,3,0};
				_expected = 346;
				_received = _obj.maxSales(vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}
			/*case 3:
			{
				int price[] = ;
				_expected = ;
				_received = _obj.maxSales(vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int price[] = ;
				_expected = ;
				_received = _obj.maxSales(vector <int>(price, price+sizeof(price)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int price[] = ;
				_expected = ;
				_received = _obj.maxSales(vector <int>(price, price+sizeof(price)/sizeof(int))); break;
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
