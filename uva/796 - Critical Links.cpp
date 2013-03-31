#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 500
#define INF 1<<20
typedef long long ll;
int N;
vector<int> G[MAX];

int ttime,f[MAX],color[MAX];
vector<pair<int,int> > ans;
int dfs(int u, int p){
	color[u]=1;
	f[u]=ttime++;
	int least=ttime;
		
	for(int i=0;i<G[u].size();i++){		
		int v=G[u][i];
		if(v==p)continue;		
		if(color[v]==0){
			int ret=dfs(v,u);
			if(ret>f[u])
                    ans.push_back(make_pair(min(u,v),max(u,v)));
			
			least=min(least,ret);
		}else{
			least=min(least,f[v]);
		}		
	}
	return least;

}
// 0 -> WHITE , 1 -> GREY, 2 -> BLACK 

int main(){	
	freopen("input","r",stdin);	
	while(scanf("%d\n",&N)==1){
		for(int i=0;i<N;i++){
			G[i].clear();
			color[i]=0;
			f[i]=INF;
		}
		ttime=0;
		ans.clear();
		for(int i=0;i<N;i++){
			int u,n,v;
			scanf("%d (%d)",&u,&n);
			for(int j=0;j<n;j++){
				scanf("%d",&v);
				G[u].push_back(v);
			}			
		}
		for(int i=0;i<N;i++)if(color[i]==0)dfs(i,-1);
		
		printf("%d critical links\n",ans.size());
		
		sort(ans.begin(),ans.end());
		
		for(int i=0;i<ans.size();i++)
			printf("%d - %d\n",ans[i].first,ans[i].second);
		printf("\n");
	
	}
	return 0;
}
