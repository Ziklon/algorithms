#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define MAXN 1100
using namespace std;
int T,M,N;
vector<int> adj[MAXN];
int seen[MAXN];
bool found;
void dfs(int u,  int tip){
    if(seen[u]!=tip){
        seen[u]=tip;
        REP(i,adj[u].size()){
            int v=adj[u][i];
            if(seen[v]!=tip)
                dfs(v,tip);
            else
             found=1;
        }
    }
}

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   scanf("%d",&T);
   REP(t,T){
      scanf("%d",&N);
      REP(i,MAXN){
        adj[i].clear();
        seen[i]=0;
      }
      REP(i,N){
         scanf("%d",&M);
         REP(j,M){
             int val;
             scanf("%d",&val);   
             adj[i+1].push_back(val);
         } 
      }
      found=0;
      int cnt=0;
      REP(i,N){        
         dfs(i,++cnt);
      }
      printf("Case #%d: ",t+1);
      if(found)
         printf("Yes\n");
      else 
        printf("No\n");
        
   }
   return 0;      
}

