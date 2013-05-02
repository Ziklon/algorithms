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
double dp[50000][52];
bool seen[50000][52];
int N,M,month;
vector<vector<int> > stocks;
double go(int money, int idx){
    if(idx+1==N)return 0;
    if(seen[money][idx])return dp[money][idx];
    seen[money][idx]=1;
    double& ref=dp[money][idx];
    
    if(idx>=1)money+=month;
    ref=go(money,idx+1);
    REP(i,M){
        if(stocks[idx][i]< stocks[N-1][i]){
           double tmp=(stocks[N-1][i]*money*1.0)/stocks[idx][i];                 
           tmp-=money;
           ref=max(ref, tmp+go(0,idx+1)); 
        }
    }    
    return ref;
}

struct StockHistory {
   int maximumEarnings( int initialInvestment, int monthlyContribution, vector <string> stockPrices ) {
       
       REP(i,stockPrices.size()){
            istringstream is(stockPrices[i]);
            vector<int> tmp;
            int val;
            while(is>>val)tmp.push_back(val);
            stocks.push_back(tmp);
       }
       month=monthlyContribution;
       N=stocks.size();
       M=stocks[0].size();
       
       double ans=go(initialInvestment,0);
       return (int)round(ans); 
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
		cout << "Testing StockHistory (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367207457;
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
		StockHistory _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int initialInvestment = 1000;
				int monthlyContribution = 0;
				string stockPrices[] = {"10 20 30", "15 24 32"};
				_expected = 500;
				_received = _obj.maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices+sizeof(stockPrices)/sizeof(string))); break;
			}
			case 1:
			{
				int initialInvestment = 1000;
				int monthlyContribution = 0;
				string stockPrices[] = {"10", "9"};
				_expected = 0;
				_received = _obj.maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices+sizeof(stockPrices)/sizeof(string))); break;
			}
			case 2:
			{
				int initialInvestment = 100;
				int monthlyContribution = 20;
				string stockPrices[] = {"40 50 60",
				                        "37 48 55",
				                        "100 48 50",
				                        "105 48 47",
				                        "110 50 52",
				                        "110 50 52",
				                        "110 51 54",
				                        "109 49 53"};
				_expected = 239;
				_received = _obj.maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices+sizeof(stockPrices)/sizeof(string))); break;
			}
			/*case 3:
			{
				int initialInvestment = ;
				int monthlyContribution = ;
				string stockPrices[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices+sizeof(stockPrices)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				int initialInvestment = ;
				int monthlyContribution = ;
				string stockPrices[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices+sizeof(stockPrices)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int initialInvestment = ;
				int monthlyContribution = ;
				string stockPrices[] = ;
				_expected = ;
				_received = _obj.maximumEarnings(initialInvestment, monthlyContribution, vector <string>(stockPrices, stockPrices+sizeof(stockPrices)/sizeof(string))); break;
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
