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

struct FactorialGCD {
   vector<pair<int,int> >factors(int n){
        ll i=2;
        vector<pair<int,int> >v;
        while(i*i<=n){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            if(cnt)v.push_back(make_pair(i,cnt));
            i++;
        }
        if(n>1)v.push_back(make_pair(n,1));
        return v;
   } 
   int factGCD( int a, int b ) {
		int ans=1;
		vector<pair<int,int> > v=factors(b);		
		REP(i,v.size()){
            int factor=v[i].first;
            int cnt=0;
            int tmp=a;
            while(tmp>0){
                cnt+=(tmp/factor);
                tmp/=factor;
            }
            cnt=min(cnt,v[i].second);
            REP(j,cnt)ans*=factor;
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
		cout << "Testing FactorialGCD (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365148131;
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
		FactorialGCD _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 5;
				int b = 20;
				_expected = 20;
				_received = _obj.factGCD(a, b); break;
			}
			case 1:
			{
				int a = 7;
				int b = 5040;
				_expected = 5040;
				_received = _obj.factGCD(a, b); break;
			}
			case 2:
			{
				int a = 0;
				int b = 2425;
				_expected = 1;
				_received = _obj.factGCD(a, b); break;
			}
			case 3:
			{
				int a = 667024;
				int b = 1;
				_expected = 1;
				_received = _obj.factGCD(a, b); break;
			}
			case 4:
			{
				int a = 4;
				int b = 40;
				_expected = 8;
				_received = _obj.factGCD(a, b); break;
			}
			case 5:
			{
				int a = 2097711064;
				int b = 2147483646;
				_expected = 2147483646;
				_received = _obj.factGCD(a, b); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.factGCD(a, b); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.factGCD(a, b); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.factGCD(a, b); break;
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
