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
int T,N,x,y,d;
#define MAXN 2501

vector<pair<int,int> >G[MAXN];
bool vis[MAXN];
int D[MAXN];
int prev[MAXN];

void dfs(int u, int cost, father){
    D[u]=cost;
    prev[u]=father;
    REP(i,G[u].size()){
        int v=G[u][i].first;
        int c=G[u][i].second;
        if(vis[v]==0){            
            dfs(v,cost+c,u);
        }    
    }    
}


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        REP(i,N){
            G[i].clear();
            vis[i]=0;
            D[i]=0;
            prev[i]=-1;
        }
        REP(i,N-1){
            scanf("%d %d %d",&x,&y,&d);
            G[x].push_back(make_pair(y,d));
            G[y].push_back(make_pair(x,d));
        }
        dfs(0,0,-1);
        
        REP(i,N){
            if(prev[i]!=-1){
                
            }
        }
        
                
   }
   return 0;      
}
