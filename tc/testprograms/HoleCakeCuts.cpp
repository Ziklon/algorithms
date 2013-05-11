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
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
typedef long long ll; 
bool G[900][900];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(int x, int y){
   queue<pair<int,int> >Q;
   G[x][y]=1;
   Q.push(make_pair(x,y));
   while(!Q.empty()){
       pair<int,int> cur=Q.front();Q.pop();
       REP(i,4){
            int X=cur.first+dx[i];
            int Y=cur.second+dy[i];
            if(min(X,Y)>=0 && max(X,Y)<900 && G[X][Y]==0){
                G[X][Y]=1;
                Q.push(make_pair(X,Y));    
            }
       }
   }
}
struct HoleCakeCuts {
   int cutTheCake( int cakeLength, int holeLength, vector <int> hs, vector <int> vs ) {
        REP(i,hs.size())hs[i]*=2;
        REP(i,vs.size())vs[i]*=2;
        memset(G,0,sizeof G);        
        for(int i=0;i<holeLength*4;i++)for(int j=0;j<holeLength*4;j++)G[200+i][200+j]=1;
        REP(i,hs.size()){
            int mid=(holeLength*2)+200;
            for(int j=0;j<900;j++)G[mid+hs[i]][j]=1;
        }
        REP(i,vs.size()){
            int mid=(holeLength*2)+200;
            for(int j=0;j<900;j++)G[j][vs[i]+mid]=1;
        }    
        int ans=0;
        REP(i,900)REP(j,900)if(G[i][j]==0){
            ans+=1;
            bfs(i,j);
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
		cout << "Testing HoleCakeCuts (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1368224190;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HoleCakeCuts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cakeLength = 5;
				int holeLength = 3;
				int horizontalCuts[] = {1, -4};
				int verticalCuts[] = {1};
				_expected = 6;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 1:
			{
				int cakeLength = 10;
				int holeLength = 5;
				int horizontalCuts[] = {};
				int verticalCuts[] = {-2, 2};
				_expected = 4;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			
			case 2:
			{
				int cakeLength = 10;
				int holeLength = 5;
				int horizontalCuts[] = {1};
				int verticalCuts[] = {-5, 5};
				_expected = 6;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			case 3:
			{
				int cakeLength = 50;
				int holeLength = 5;
				int horizontalCuts[] = {40, -40};
				int verticalCuts[] = {20, 0, -20};
				_expected = 12;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}
			/*case 4:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int cakeLength = ;
				int holeLength = ;
				int horizontalCuts[] = ;
				int verticalCuts[] = ;
				_expected = ;
				_received = _obj.cutTheCake(cakeLength, holeLength, vector <int>(horizontalCuts, horizontalCuts+sizeof(horizontalCuts)/sizeof(int)), vector <int>(verticalCuts, verticalCuts+sizeof(verticalCuts)/sizeof(int))); break;
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
