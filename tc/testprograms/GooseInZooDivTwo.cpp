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
int P[3000];

int find(int u){
    if(P[u]==u)return u;
    return P[u]=find(P[u]);
}
void join(int u, int v){
    P[find(u)]=find(v);
}
vector<pair<int,int> >birds;

struct GooseInZooDivTwo {
   int count( vector <string> field, int dist ) {
		
		REP(i,3000)P[i]=i;
		REP(i,field.size())REP(j,field[i].size())if(field[i][j]=='v')birds.push_back(make_pair(i,j));
		
		REP(i,birds.size())REP(j,birds.size())if(i!=j && abs(birds[i].first-birds[j].first)+abs(birds[i].second-birds[j].second)<=dist)
            join(i,j);
        set<int> S;
        REP(i,birds.size())S.insert(find(i));
        int ans=1;
        
        REP(i,S.size())ans=(ans*2)%MOD;
        
        ans=(ans-1+MOD)%MOD;
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
		cout << "Testing GooseInZooDivTwo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367614205;
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
		GooseInZooDivTwo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {"vvv"};
				int dist = 0;
				_expected = 7;
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
				_expected = 1;
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
				_expected = 797922654;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}
			/*case 4:
			{
				string field[] = ;
				int dist = ;
				_expected = ;
				_received = _obj.count(vector <string>(field, field+sizeof(field)/sizeof(string)), dist); break;
			}*/
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
