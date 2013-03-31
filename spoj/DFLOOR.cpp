#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
char board[16][16];
int maze[16][16];
int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};
int r,c;
bool check(int x, int y){
	if(maze[x][y]==0)return 0;
	REP(i,0,4){
		int X=di[i]+x;
		int Y=dj[i]+y;
		if(min(X,Y)>=0 && X<c && Y<r){
			if(maze[X][Y]==0)return 1;
		}
	}
	return 0;
}

void update(int x, int y){
	maze[x][y]=maze[x][y]^1;
	REP(i,0,4){
		int X=di[i]+x;
		int Y=dj[i]+y;
		if(min(X,Y)>=0 && X<c && Y<r)
			maze[X][Y]=maze[X][Y]^1;
	}
}

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   while(cin>>r>>c){
		if(r==0 && c==0)break;
   	REP(i,0,c)
   		REP(j,0,r)
   			cin>>board[i][j];
   	int ans=1<<20;
   	int msk=0;
		REP(i,0,c)
			printf("%s\n",board[i]);
			
		REP(mask,0,1<<c){
			
			REP(i,0,c)
				REP(j,0,r)
					maze[i][j]=board[i][j]-'0';
			
			int cn=0;
			REP(i,0,c)
				if(mask&(1<<i))
					REP(j,0,r)
						if(check(i,j)){
							cn++;
							update(i,j);
						}
			bool ok=1;
			REP(i,0,c)
				REP(j,0,r)
					if(maze[i][j]==0)
						ok=0;
			if(ans>cn && ok){
				ans=cn;
				msk=mask;
			}
			
		}
		
		printf("%d\n",ans);
		REP(i,0,c)
				REP(j,0,r)
					maze[i][j]=board[i][j]-'0';
		REP(i,0,c)
				if(msk&(1<<i))
					REP(j,0,r)
						if(check(i,j)){
							update(i,j);
							printf("%d %d\n",i+1,j+1);
						}
		
		
	}
   //system("pause");
   return 0;
}
