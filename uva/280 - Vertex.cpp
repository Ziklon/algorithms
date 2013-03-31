#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

vector<int> G[101];
bool vis[101];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
		dfs(G[x][i]);
}
int main(){
	//ios::sync_with_stdio(false);
	//freopen("input","r",stdin);
	//freopen("output.txt","w",stdout);	
	int N;
	while(scanf("%d",&N)==1 && N)	{
		for(int i=1;i<=N;i++)G[i].clear();		
		int u,v,q,cnt;
		while(scanf("%d",&u)==1 && u){
			while(scanf("%d",&v)==1 && v)
				G[u].push_back(v);
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			scanf("%d",&u);
			memset(vis,0,sizeof vis);			
			for(int j=0;j<G[u].size();j++)dfs(G[u][j]);			
			cnt=0;
			for(int j=1;j<=N;j++)if(vis[j]==0)cnt++;	
			printf("%d",cnt);			
			for(int j=1;j<=N;j++)if(vis[j]==0)printf(" %d",j);
			printf("\n");			
		}		
	}
	return 0;
}
