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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int R,C,n,xi,yi,xf,yf,t;
bool G[1001][1001];
bool vis[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct nodo{
	int x,y,d;
	nodo(int a, int b, int c){
		x=a;y=b;d=c;
	}
};


void solve(){
	while(scanf("%d %d",&R,&C)==2){
		if(R==0 && C==0)break;
		scanf("%d",&n);
		fill(G,0);
		fill(vis,0);
		REP(i,0,n){
			scanf("%d",&xi);
			scanf("%d",&t);
			REP(j,0,t){
				scanf("%d",&yi);
				G[xi][yi]=1;
			}
		}
		scanf("%d %d",&xi,&yi);
		scanf("%d %d",&xf,&yf);
		queue<nodo>Q;
		Q.push(nodo(xi,yi,0));
		vis[xi][yi]=1;
		int ans=-1;
		while(!Q.empty()){
			nodo cur=Q.front();Q.pop();
			if(cur.x==xf && cur.y==yf){
				ans=cur.d;
				break;
			}
			REP(i,0,4){
				int X=cur.x+dx[i];
				int Y=cur.y+dy[i];
				if(min(X,Y)>=0 && X<R && Y<C && !G[X][Y] && !vis[X][Y]){
					vis[X][Y]=1;
					Q.push(nodo(X,Y,cur.d+1));				
				}			
			}
		}
		printf("%d\n",ans);		
	
	}
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

