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
#define INF 1<<30
typedef long long ll; 
int N;
int dist[55];
struct TravelOnMars {
   int minTimes( vector <int> range, int startCity, int endCity ) {
		N=range.size();
		REP(i,55)dist[i]=INF;
		dist[startCity]=0;
		priority_queue<pair<int,int> >Q;
		Q.push(make_pair(0,startCity));
		while(!Q.empty()){
            int cost=abs(Q.top().first);
            int u=Q.top().second;
            Q.pop();
            for(int i=-range[u];i<=range[u];i++){
                int v=(u+i+N)%N;
                if(dist[v]>cost+1){
                    dist[v]=cost+1;
                    Q.push(make_pair(-(cost+1),v));
                }                
            }            
		}		
		return dist[endCity];
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
		cout << "Testing TravelOnMars (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1371623109;
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
		TravelOnMars _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int range[] = {2,1,1,1,1,1};
				int startCity = 1;
				int endCity = 4;
				_expected = 2;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 1:
			{
				int range[] = {2,1,1,1,1,1};
				int startCity = 4;
				int endCity = 1;
				_expected = 3;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 2:
			{
				int range[] = {2,1,1,2,1,2,1,1};
				int startCity = 2;
				int endCity = 6;
				_expected = 3;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 3:
			{
				int range[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
				int startCity = 6;
				int endCity = 13;
				_expected = 4;
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
