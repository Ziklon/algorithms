/*
ID: winftc2
PROG: castle
LANG: C++
*/
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
#define oo 1<<30
using namespace std;
int m,n,val;
int G[55][55];
bool vis[55][55];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int SIZE[55][55];

vector<pair<int,int> > v;

int dfs(int x, int y){
	vis[x][y]=1;
	int ans=1;
	REP(j,0,4){
		if((G[x][y]&(1<<j))==0){			
			int X=x+dx[j];
			int Y=y+dy[j];
			if(min(X,Y)>=0 && X<n && Y<m  &&!vis[X][Y])
				ans+=dfs(X,Y);
		}
	}
	v.push_back(make_pair(x,y));
	return ans;

}

void solve(){
	scanf("%d %d",&m,&n);
	int hab=0;
	int tam=0;
	REP(i,0,n){
		REP(j,0,m){
			scanf("%d",&val);
			G[i][j]=val;
		}
		
	}
	fill(vis,0);
	REP(i,0,n)REP(j,0,m)if(!vis[i][j]){
		v.clear();
		int val=dfs(i,j);
		REP(i,0,v.sz)
			SIZE[v[i].first][v[i].second]=val;
		tam=max(tam,val);
		hab++;
	}
	REP(i,0,n){
		REP(j,0,m)printf("%d ",SIZE[i][j]);
		printf("\n");
	}
	printf("%d\n",hab);
	printf("%d\n",tam);	
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

