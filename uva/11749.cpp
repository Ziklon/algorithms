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
#define EPS 1e-9

using namespace std;

long long G[501][501],mxd,d,limit=-(1LL<<40);
int N,M,a,b;
bool vis[501];


int get_num(int a, int b){
	
	queue<int> Q;
	vis[a]=vis[b]=1;
	Q.push(a);Q.push(b);
	int ans=2;
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		REP(i,1,N+1){
			if(!vis[i] && mxd==G[cur][i]){
				ans++;
				vis[i]=1;
				Q.push(i);
			}
		}	
	}	
	return ans;
}

void solve(){
	while(scanf("%d %d\n",&N,&M)==2){
		if(N==M && N==0)break;
		mxd=limit;		
		REP(i,0,N+1)REP(j,0,N+1)G[i][j]=mxd;		
		REP(i,0,M){
			scanf("%d %d %lld\n",&a,&b,&d);
			G[a][b]=max(G[a][b],d);
			G[b][a]=max(G[b][a],d);
			mxd=max(mxd,d);
		}
		int res=0;
		fill(vis,0);	
		REP(i,1,N+1)REP(j,i+1,N+1)if(G[i][j]==mxd && !vis[i] && !vis[j])
										res=max(res,get_num(i,j));		
		printf("%d\n",res);			
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

