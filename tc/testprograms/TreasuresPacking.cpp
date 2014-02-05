#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <sstream>
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;
struct node{
    int cost, weight;
    char can_divided;
    node(){}
    node(int w, int c, char z){
       cost=c;weight=w;
       can_divided=z; 
    }
};
int N;
node ts[50];

double dp[50][10001];
bool seen[50][10001];



double solve(int idx, int w, int after){
    if(idx>=N){
        if(after>=N)return 0;
        double cost = (1.0*min(w, ts[after].weight)*ts[after].cost*1.0)/(ts[after].weight);
        return cost; 
    }
    if(seen[idx][w])return dp[idx][w];
    double &ref = dp[idx][w];
    ref = solve(idx+1,w,after);   
    
    if(idx!=after && ts[idx].weight<=w)ref=max(ref,solve(idx+1,w-ts[idx].weight,after)+ts[idx].cost);
    seen[idx][w]=1;    
    return ref;    
}


struct TreasuresPacking {
	double maximizeCost(vector <string> treasures, int W) {
		N=treasures.size();
		for(int i=0;i<N;i++){
            istringstream is(treasures[i]);
            int w,c;
            char z;
            is>>w>>c>>z;
            ts[i]= node(w,c,z);           
		}
		double ans = 0;
		for(int i=0;i<=N;i++){
           
            if(i<N && ts[i].can_divided=='N')continue;
             memset(seen,0,sizeof seen);
            ans=max(ans,solve(0,W,i));
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
		cout << "Testing TreasuresPacking (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391524551;
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
		TreasuresPacking _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string treasures[] = {"100 100 N", "100 100 N", "130 10 Y"};
				int W = 150;
				_expected = 103.84615384615384;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}
			case 1:
			{
				string treasures[] = {"100 100 N", "100 100 N", "100 1000 Y"};
				int W = 150;
				_expected = 1000.0;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}
			case 2:
			{
				string treasures[] = {"207 1459 Y", "150 6867 N", "694 3494 Y", "417 7479 N"};
				int W = 650;
				_expected = 14931.00966183575;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}
			case 3:
			{
				string treasures[] = {"350 2765 Y", "258 560 Y", "120 9325 N", "879 302 Y",
				                      "611 2674 Y", "774 2273 Y", "318 1572 Y"};
				int W = 3301;
				_expected = 19467.907849829353;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}
			/*case 4:
			{
				string treasures[] = ;
				int W = ;
				_expected = ;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}*/
			/*case 5:
			{
				string treasures[] = ;
				int W = ;
				_expected = ;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}*/
			/*case 6:
			{
				string treasures[] = ;
				int W = ;
				_expected = ;
				_received = _obj.maximizeCost(vector <string>(treasures, treasures+sizeof(treasures)/sizeof(string)), W); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

//END CUT HERE
