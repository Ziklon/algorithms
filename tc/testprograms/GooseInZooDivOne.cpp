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
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define MOD 1000000007
typedef long long ll; 

int P[3000],N;
int find(int u){
    if(P[u]==u)return u;
    return P[u]=find(P[u]);
}
void join(int u, int v){
    P[find(u)]=find(v);
}
vector<pair<int,int> > birds;

map<int,int> M;

vector<int> vi;

ll dp[2501][3][2];


ll go(int idx, int cnt, int puso){
   if(idx>=vi.size()){
       if(cnt%2==0 && puso>0)return 1;
       return 0;    
   }
   ll& ref=dp[idx][cnt][puso];
   if(ref!=-1)return ref;
   ref=go(idx+1,cnt,puso)%MOD;
   ref=(ref+go(idx+1,(cnt+vi[idx])&1,1))%MOD;
   return ref;    
}


struct GooseInZooDivOne {
   int count( vector <string> field, int dist ) {
		
		REP(i,3000)P[i]=i;
		
		
		REP(i,field.size())REP(j,field[i].size())if(field[i][j]=='v')birds.push_back(make_pair(i,j));
		
		N=birds.size();
		REP(i,N)REP(j,N) if(i!=j && abs(birds[i].first-birds[j].first)+abs(birds[i].second-birds[j].second)<=dist)
                    join(i,j);
		
		REP(i,N)M[find(i)]++;
		
		FOREACH(it,M)vi.push_back(it->second);
		
		memset(dp,-1,sizeof dp);
		
		return (int)go(0,0,0);
		
		
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
		cout << "Testing GooseInZooDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367543394;
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
		GooseInZooDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {"vvv"};
				int dist = 0;
				_expected = 3;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 1:
			{
				string field[] = {"."};
				int dist = 100;
				_expected = 0;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 2:
			{
				string field[] = {"vvv"};
				int dist = 1;
				_expected = 0;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 3:
			{
				string field[] = {"v.v..................v............................"
				                 ,".v......v..................v.....................v"
				                 ,"..v.....v....v.........v...............v......v..."
				                 ,".........vvv...vv.v.........v.v..................v"
				                 ,".....v..........v......v..v...v.......v..........."
				                 ,"...................vv...............v.v..v.v..v..."
				                 ,".v.vv.................v..............v............"
				                 ,"..vv.......v...vv.v............vv.....v.....v....."
				                 ,"....v..........v....v........v.......v.v.v........"
				                 ,".v.......v.............v.v..........vv......v....."
				                 ,"....v.v.......v........v.....v.................v.."
				                 ,"....v..v..v.v..............v.v.v....v..........v.."
				                 ,"..........v...v...................v..............v"
				                 ,"..v........v..........................v....v..v..."
				                 ,"....................v..v.........vv........v......"
				                 ,"..v......v...............................v.v......"
				                 ,"..v.v..............v........v...............vv.vv."
				                 ,"...vv......v...............v.v..............v....."
				                 ,"............................v..v.................v"
				                 ,".v.............v.......v.........................."
				                 ,"......v...v........................v.............."
				                 ,".........v.....v..............vv.................."
				                 ,"................v..v..v.........v....v.......v...."
				                 ,"........v.....v.............v......v.v............"
				                 ,"...........v....................v.v....v.v.v...v.."
				                 ,"...........v......................v...v..........."
				                 ,"..........vv...........v.v.....................v.."
				                 ,".....................v......v............v...v...."
				                 ,".....vv..........................vv.v.....v.v....."
				                 ,".vv.......v...............v.......v..v.....v......"
				                 ,"............v................v..........v....v...."
				                 ,"................vv...v............................"
				                 ,"................v...........v........v...v....v..."
				                 ,"..v...v...v.............v...v........v....v..v...."
				                 ,"......v..v.......v........v..v....vv.............."
				                 ,"...........v..........v........v.v................"
				                 ,"v.v......v................v....................v.."
				                 ,".v........v................................v......"
				                 ,"............................v...v.......v........."
				                 ,"........................vv.v..............v...vv.."
				                 ,".......................vv........v.............v.."
				                 ,"...v.............v.........................v......"
				                 ,"....v......vv...........................v........."
				                 ,"....vv....v................v...vv..............v.."
				                 ,".................................................."
				                 ,"vv........v...v..v.....v..v..................v...."
				                 ,".........v..............v.vv.v.............v......"
				                 ,".......v.....v......v...............v............."
				                 ,"..v..................v................v....v......"
				                 ,".....v.....v.....................v.v......v......."};
				int dist = 3;
				_expected = 898961330;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			case 4:
			{
				string field[] ={"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv"} ;
				int dist =0 ;
				_expected = 1122;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			/*case 5:
			{
				string field[] = ;
				int dist = ;
				_expected = ;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}*/
			/*case 6:
			{
				string field[] = ;
				int dist = ;
				_expected = ;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
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
