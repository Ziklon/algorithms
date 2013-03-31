#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
#define MAXN 25
bool vis[MAXN];
int T,N,M,x,y,ans;
vector<int> G[MAXN];

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!vis[v]){
            dfs(v);
        }else{
            ans=0;
        }
    }    
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d %d",&N,&M);
        ans=1;
        memset(vis,0,sizeof vis);
        REP(i,N+1)G[i].clear();
        
        REP(i,M){
            scanf("%d %d",&x,&y);
            G[x].push_back(y);            
        }
        dfs(1);
        REP(i,N+1)if(i>0 && vis[i]==0)ans=0;
        printf("%d\n",ans);        
   }
   return 0;      
}
