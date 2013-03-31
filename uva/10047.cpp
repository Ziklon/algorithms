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
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;

struct node{
	int x,y,dir,dis,c;
	node(){}
	node(int _x, int _y, int _dir, int _dis, int _c){
		x=_x;y=_y;dir=_dir;dis=_dis;
		c=_c;
	}
};
bool vis[26][26][4][5];
char buff[27][27];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1},dis;
int M,N;


void solve(){
	int t=0;
	while(scanf("%d %d\n",&M,&N)==2){
		if(M==N && M==0)break;
		int xs,ys,xt,yt;
		fill(vis,0);		
		if(t>0)printf("\n");
		REP(i,0,M){
			REP(j,0,N){
				scanf("%c",&buff[i][j]);
				if(buff[i][j]=='S')xs=i,ys=j;
				if(buff[i][j]=='T')xt=i,yt=j;			
			}
			scanf("\n");
		}
		queue<node>Q;		
		Q.push(node(xs,ys,0,0,2));
		vis[xs][ys][0][2]=1;
		dis=INF;
		while(!Q.empty()){
			node p=Q.front();Q.pop();
			if(p.x==xt && p.y==yt && p.c==2){
				dis=p.dis;
				break;
			}
			
			REP(i,1,4){
				if(i==2)continue;
				int dir=(p.dir+i)%4;				
				if(vis[p.x][p.y][dir][p.c]==0){
					Q.push(node(p.x,p.y,dir,p.dis+1,p.c));
					vis[p.x][p.y][dir][p.c]=1;
				}
			}	
			int x=p.x+dx[p.dir];
			int y=p.y+dy[p.dir];
			int c=(p.c+1)%5;
			if(min(x,y)<0 || x>=M || y>=N)continue;	
				
			if(vis[x][y][p.dir][c]==0 && buff[x][y]!='#'){
					Q.push(node(x,y,p.dir,p.dis+1,c));
					vis[x][y][p.dir][c]=1;
			}			
		}
		printf("Case #%d\n",++t);
		if(dis<INF)
			printf("minimum time = %d sec\n",dis);
		else
			printf("destination not reachable\n");
		
		
		
	}	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

