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
#include <cstdio>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 

int seen[55];

struct TravelOnMars2 {
   int minTimes( vector <int> range, int startCity, int endCity ) {
        
        REP(i,55)seen[i]=-1;
        
        seen[startCity]=0;
        queue<int>Q;
        Q.push(startCity);
        int N=range.size();
        while(!Q.empty()){
            int u=Q.front();Q.pop();            
            if(u==endCity)return seen[u];            
            for(int len=-range[u];len<=range[u];len++){
                int v=(u+N+len)%N;
                if(seen[v]==-1){
                    seen[v]=seen[u]+1;
                    Q.push(v);
                }                
            }        
            
        }
        return -1;      
        
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
		cout << "Testing TravelOnMars2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1372778883;
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
		TravelOnMars2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int range[] = {2, 1, 1, 1, 1, 1};
				int startCity = 1;
				int endCity = 4;
				_expected = 2;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 1:
			{
				int range[] = {2, 1, 1, 2, 1, 2, 1, 1};
				int startCity = 2;
				int endCity = 6;
				_expected = 3;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 2:
			{
				int range[] = {3, 2, 1, 1, 3, 1, 2, 2, 1, 1, 2, 2, 2, 2, 3};
				int startCity = 6;
				int endCity = 13;
				_expected = 4;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 3:
			{
				int range[] = {2, 4, 2, 3, 4, 1, 4, 2, 5, 4, 3, 3, 5, 4, 5, 2, 2, 4, 4, 3, 3, 4, 2, 3, 5, 4, 2, 4, 1, 3, 2, 3, 4, 1, 1, 4, 4, 3, 5, 3, 2, 1, 4, 1, 4};
				int startCity = 24;
				int endCity = 8;
				_expected = 5;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			/*case 4:
			{
				int range[] = ;
				int startCity = ;
				int endCity = ;
				_expected = ;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}*/
			/*case 5:
			{
				int range[] = ;
				int startCity = ;
				int endCity = ;
				_expected = ;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}*/
			/*case 6:
			{
				int range[] = ;
				int startCity = ;
				int endCity = ;
				_expected = ;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
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
