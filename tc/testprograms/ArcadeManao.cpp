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
#define INF 1<<20
int dist[55][55];



struct ArcadeManao {
   int shortestLadder( vector <string> level, int coinRow, int coinColumn ) {
       REP(i,55)REP(j,55)dist[i][j]=INF;
              
       priority_queue<pair<int,pair<int,int> > > Q;
       REP(i,level[0].size()){
            Q.push(make_pair(0,make_pair(level.size()-1,i)));
            dist[level.size()-1][i]=0;
       }
       while(!Q.empty()){
           
           int cost=abs(Q.top().first);
           int x=Q.top().second.first;
           int y=Q.top().second.second;
           Q.pop();
           
           //cout<<x<<" "<<y<<" --> "<<cost<<endl;
           //if(x+1==coinRow && y+1==coinColumn)return cost;
           //he can move left or right
           REP(i,51)if(i>=1){
                if((x-i)>=0 && level[x-i][y]=='X'){
                    int cc=max(i,cost);                    
                    if(dist[x-i][y]> (cc)){
                        Q.push(make_pair(-cc,make_pair(x-i,y)));
                        dist[x-i][y]=cc;    
                    }    
                }
                if((x+i)<level.size() && level[x+i][y]=='X'){
                    int cc=max(i,cost);
                    if(dist[x+i][y]>(cc)){
                        Q.push(make_pair(-cc,make_pair(x+i,y)));
                        dist[x+i][y]=cc;
                    }
                }
           }
           if(y+1<level[0].size() && level[x][y+1]=='X'){
                if(dist[x][y+1]> (cost)){
                    Q.push(make_pair(-cost,make_pair(x,y+1)));
                    dist[x][y+1]=cost;
                }
           }
           if(y>=1 && level[x][y-1]=='X'){
                if(dist[x][y-1]> (cost)){
                    Q.push(make_pair(-cost,make_pair(x,y-1)));
                    dist[x][y-1]=cost;
                }
           }
                
       }
       return dist[coinRow-1][coinColumn-1];       
       
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
		cout << "Testing ArcadeManao (256.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365761777;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 256.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ArcadeManao _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string level[] = {"XXXX....",
				                  "...X.XXX",
				                  "XXX..X..",
				                  "......X.",
				                  "XXXXXXXX"};
				int coinRow = 2;
				int coinColumn = 4;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 1:
			{
				string level[] = {"XXXX",
				                  "...X",
				                  "XXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 1;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 2:
			{
				string level[] = {"..X..",
				                  ".X.X.",
				                  "X...X",
				                  ".X.X.",
				                  "..X..",
				                  "XXXXX"};
				int coinRow = 1;
				int coinColumn = 3;
				_expected = 4;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 3:
			{
				string level[] = {"X"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 0;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			case 4:
			{
				string level[] = {"XXXXXXXXXX",
				                  "...X......",
				                  "XXX.......",
				                  "X.....XXXX",
				                  "..XXXXX..X",
				                  ".........X",
				                  ".........X",
				                  "XXXXXXXXXX"};
				int coinRow = 1;
				int coinColumn = 1;
				_expected = 2;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}
			/*case 5:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 6:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
			}*/
			/*case 7:
			{
				string level[] = ;
				int coinRow = ;
				int coinColumn = ;
				_expected = ;
				_received = _obj.shortestLadder(vector <string>(level, level+sizeof(level)/sizeof(string)), coinRow, coinColumn); break;
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
