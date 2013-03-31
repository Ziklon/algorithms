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

bool vis[55][55][105];

struct Node{
	int x,y,b,t;
	Node(int _x, int _y, int _b, int _t){
		x=_x;y=_y;b=_b;t=_t;
	}
	bool operator < (const Node p)const{
		if(p.t==t)return p.b<b;
		return p.t<t;
	}
};
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

struct BombMan {
   int shortestPath( vector <string> maze, int bombs ) {
		priority_queue<Node> Q;
		int sx,sy,ex,ey;
		REP(i,maze.size())REP(j,maze[i].size()){
			if(maze[i][j]=='B')sx=i,sy=j;
			if(maze[i][j]=='E')ex=i,ey=j;			
		}
			
		Q.push(Node(sx,sy,0,0));
		memset(vis,0,sizeof vis);
		vis[sx][sy][0]=1;		
		while(!Q.empty()){
			Node cur=Q.top();Q.pop();
			if(cur.x==ex && cur.y==ey)return cur.t;	
			REP(i,4){
				int X=cur.x+dx[i];
				int Y=cur.y+dy[i];				
				if(min(X,Y)>=0 && X<maze.size() && Y<maze[0].size()){
					if(maze[X][Y]=='#'){						
						//# wall
						if(vis[X][Y][cur.b+1]==0 && (cur.b+1)<=bombs){
							Q.push(Node(X,Y,cur.b+1,cur.t+3));
							vis[X][Y][cur.b+1]=1;
						}
					}else{
						//. free
						if(vis[X][Y][cur.b]==0){
							Q.push(Node(X,Y,cur.b,cur.t+1));
							vis[X][Y][cur.b]=1;
						}	
					}	
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
		cout << "Testing BombMan (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1358450776;
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
		BombMan _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string maze[] = {".....B.",
				                 ".#####.",
				                 ".#...#.",
				                 ".#E#.#.",
				                 ".###.#.",
				                 "......."};
				int bombs = 1;
				_expected = 8;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
			}
			case 1:
			{
				string maze[] = {"B.#.#.#...E"};
				int bombs = 2;
				_expected = -1;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
			}
			case 2:
			{
				string maze[] = {"..#####",
				                 "B.#####",
				                 "..#####",
				                 "#######",
				                 "####...",
				                 "####.E."};
				int bombs = 4;
				_expected = 17;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
			}
			case 3:
			{
				string maze[] = {".#.#.#.#B#...#.#...#.#...#.#...#.#...#.#.#.......",
				                 ".#.#.#.#.#.###.###.#.###.#.#.###.###.#.#.#.###.##",
				                 ".#.#.#...#.#.#.#.#.#...#.....#.#.#...#...#.#.#...",
				                 ".#.#.###.#.#.#.#.#.###.#.#####.#.###.###.#.#.###.",
				                 ".............#.#...#...#.....#.#.#...#.#.#.....#.",
				                 "##.#######.###.#.#####.#.#####.#.###.#.#.#.#.####",
				                 ".#.#.....#...#...#.#...#...#.#.#...#...#...#.....",
				                 ".#######.#.#####.#.#.#.#.###.#.###.#.#####.#.####",
				                 ".#.#.#.#...#.#.#.#.#.#.......#...#.#...#.#.#.....",
				                 ".#.#.#.###.#.#.#.#.#####.#####.###.###.#.#.######",
				                 ".....#...#.#...#...#...#...#...#...#.#.#.........",
				                 "####.###.#.###.###.#.###.#.#.###.###.#.#.########",
				                 ".......#.........#.#.#.#.#.#.#.#.........#...#...",
				                 ".#.###.#########.#.#.#.#.###.#.#####.#.#.#.###.##",
				                 ".#.#.........#.#.#.#.#.....#.#.#.....#.#.........",
				                 "############.#.#.#.#.#.#####.#.#.################",
				                 ".#...........#...#.#.#.#...#.#.#...#.#.#.....#...",
				                 ".#####.#####.###.#.#.#.#.###.#.#.###.#.#.#####.##",
				                 ".......#...#.#.#.....#...#...#.#.#.#.#...........",
				                 "##########.#.#.#####.#.###.###.#.#.#.#.##########",
				                 ".....#...#.....#.#...#.......#.#...#.......#.....",
				                 "##.#.###.#.###.#.#.#.#.#####.#.#.###.#######.####",
				                 "...#...#...#.......#.....#.#...#...#.......#.....",
				                 "####.#.#.#########.#.###.#.#####.###.#.#######.##",
				                 ".#...#...#.........#.#.....#.........#.#.#.#.....",
				                 ".#####.#.#.###.#######.#.###.#.#########.#.#.####",
				                 ".......#.#.#...#.......#.....#.#.#.......#.#.#.#.",
				                 "########.#.#.#.#####.#.###.#.###.#.#######.#.#.#.",
				                 ".........#.#.#.#.....#...#.#.........#.#.........",
				                 "################.#.#.#.#.#.#.#.#######.#.########",
				                 ".................#.#.#.#.#.#.#...........#.......",
				                 "########.#####.#.###.#.#.#####.###.#.#####.###.##",
				                 ".........#...#.#...#.#.#...#.....#.#.........#...",
				                 ".#####.#####.#.###.#.###.#.#.#.#.#.#####.#.###.#.",
				                 ".#.....#.........#.#.#...#.#.#.#.#.#.....#...#.#.",
				                 "####.#####.###.#.#.#.#.#.#.###.###.#.#.#.#.#####.",
				                 ".....#.....#.#.#.#.#.#.#.#.#...#...#.#.#.#...#...",
				                 "####.#.#.###.#.#.###.#.###.#.#.#####.#.#.#.######",
				                 ".....#.#.#.#...#...#.#...#.#.#...#...#.#.#.......",
				                 "##########.#.#.#.#####.###.#.#.###.#.###.#####.##",
				                 "...#.#...#...#.#.....#.#...#.#...#.#.#.......#...",
				                 ".#.#.#.#.#.#.#.#.#.#.###.#.#########.###.#.#.#.#.",
				                 ".#.#...#...#.#.#.#.#...#.#...#.......#...#.#.#.#.",
				                 "##.###.#.#.###.#.#.#.#.#####.#.#.#.###.#.########",
				                 ".......#.#...#.#.#.#.#.#.....#.#.#...#.#.........",
				                 "####.#######.#.#####.#.###.#.#.###.#.#.#.########",
				                 "E..#.......#.#.....#.#.#.#.#.#.#...#.#.#.........",
				                 "##.#.#.#.###.###.###.###.#.#.###.#.#.#.#.#######.",
				                 ".....#.#...#.#.....#.#.....#...#.#.#.#.#.....#..."};
				int bombs = 3;
				_expected = 76;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
			}
			/*case 4:
			{
				string maze[] = ;
				int bombs = ;
				_expected = ;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
			}*/
			/*case 5:
			{
				string maze[] = ;
				int bombs = ;
				_expected = ;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
			}*/
			/*case 6:
			{
				string maze[] = ;
				int bombs = ;
				_expected = ;
				_received = _obj.shortestPath(vector <string>(maze, maze+sizeof(maze)/sizeof(string)), bombs); break;
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
