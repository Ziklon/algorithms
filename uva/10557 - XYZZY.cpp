#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define INF 1<<20
using namespace std;
vector<vector<pair<int,int> > > Adj;

int dist[120];
int N,P,M,v;
bool vis[120];


bool dfs(int u){
    if(u==N-1)return 1;
    vis[u]=1;
    int ans=0;
    REP(i,Adj[u].size()){
        pair<int,int> cur=Adj[u][i];        
        if(vis[cur.first]==0){
            ans|=dfs(cur.first);            
        }
    }
    return ans;

}
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif    
   while(scanf("%d",&N)==1 && N>0){
       Adj.clear();
       Adj.resize(N);
       memset(vis,0,sizeof vis);
       
       REP(i,N){
            scanf("%d %d",&P,&M);
            REP(j,M){
                scanf("%d",&v);v--;
                Adj[i].push_back(make_pair(v,P));
                
            }
       }
       bool can=0;
       REP(i,N)dist[i]=-(INF);
       dist[0]=100;
       
        REP(u,N){
            if(dist[u]<=0)continue;
            REP(j,Adj[u].size()){
                pair<int,int> v=Adj[u][j];                    
                dist[v.first]=max(dist[v.first],dist[u]+v.second);
            }
        }
       bool hasCycle=0;
       
       REP(u,N)REP(j,Adj[u].size()){
            pair<int,int> v=Adj[u][j];
            if(dist[v.first]<(dist[u]+v.second) && dist[u]>0 && dfs(u)){
                hasCycle=1;
            }
       }  
       if(hasCycle || dist[N-1]>0)can=1;      
       if(can)puts("winnable");
       else puts("hopeless");
   }
   return 0;      
}
