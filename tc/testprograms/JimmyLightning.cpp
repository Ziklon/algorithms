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
#include <cstring>
#include <cstdlib> 
#include <ctime>
using namespace std; 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
typedef long long ll; 
#define INF 1<<30

vector<pair<int,int> >diam[55]; 
vector<int> expire;
int dp[51][1100];

int go(int idx, int tim){
    if(idx==-1)return 0;
    if(expire[idx]<=tim)return -INF;
    int& ref=dp[idx][tim];    
    if(ref!=-1)return ref;
    ref=-INF;
    if(expire[idx]>tim)ref=max(ref,go(idx-1,tim));
    for(int i=0;i<diam[idx].size();i++){
        int cost=diam[idx][i].second;
        int profit=diam[idx][i].first;
        if((cost+tim)<expire[idx])ref=max(ref, go(idx,tim+cost)+profit);
    }    
    return ref;    
}


struct JimmyLightning {
   int robTheBank( vector <int> doors, vector <string> diamonds ) {
		int ans,i,j;
		memset(dp,-1,sizeof dp);
		expire=doors;		
		REP(i,diamonds.size()){
            istringstream is(diamonds[i]);
            int a,b,c;
            is>>a>>b>>c;
            diam[c-1].push_back(make_pair(a,b));            
        }
        ans=go(doors.size()-1,0);
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
		cout << "Testing JimmyLightning (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365112562;
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
		JimmyLightning _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int doors[] = {6};
				string diamonds[] = {"2 1 1"};
				_expected = 10;
				_received = _obj.robTheBank(vector <int>(doors, doors+sizeof(doors)/sizeof(int)), vector <string>(diamonds, diamonds+sizeof(diamonds)/sizeof(string))); break;
			}
			case 1:
			{
				int doors[] = {1};
				string diamonds[] = {"999 1 1"};
				_expected = 0;
				_received = _obj.robTheBank(vector <int>(doors, doors+sizeof(doors)/sizeof(int)), vector <string>(diamonds, diamonds+sizeof(diamonds)/sizeof(string))); break;
			}
			case 2:
			{
				int doors[] = {10, 5, 2};
				string diamonds[] = {"1 1 1",
				                     "2 1 2",
				                     "3 1 3"};
				_expected = 14;
				_received = _obj.robTheBank(vector <int>(doors, doors+sizeof(doors)/sizeof(int)), vector <string>(diamonds, diamonds+sizeof(diamonds)/sizeof(string))); break;
			}
			/*case 3:
			{
				int doors[] = ;
				string diamonds[] = ;
				_expected = ;
				_received = _obj.robTheBank(vector <int>(doors, doors+sizeof(doors)/sizeof(int)), vector <string>(diamonds, diamonds+sizeof(diamonds)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				int doors[] = ;
				string diamonds[] = ;
				_expected = ;
				_received = _obj.robTheBank(vector <int>(doors, doors+sizeof(doors)/sizeof(int)), vector <string>(diamonds, diamonds+sizeof(diamonds)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int doors[] = ;
				string diamonds[] = ;
				_expected = ;
				_received = _obj.robTheBank(vector <int>(doors, doors+sizeof(doors)/sizeof(int)), vector <string>(diamonds, diamonds+sizeof(diamonds)/sizeof(string))); break;
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
