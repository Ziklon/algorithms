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
#define INF 1<<30
#define MAXN 10000

vector<int> G[MAXN];
int N,T,x,y;
int dfs_prev[MAXN];
bool vis[MAXN];

int dp[MAXN+2][2],ans;

void dfs(int u){
    vis[u]=1;
    REP(i,G[u].size()){
        int v=G[u][i];
        if(vis[v]==0){          
            dfs_prev[v]=u;
            dfs(v);
        }
    }
}

int go(int node, int used){
    int child=0;    
    int& ans=dp[node][used];
    if(ans!=-1)return ans;    
    REP(i,G[node].size()){
        int v=G[node][i];
        if(dfs_prev[v]==node)
            child++;
    }  
    if(child==0) return ans=100*(used==1?0:1);
    ans=INF;
    vector<int> cost_a(child);
    vector<int> cost_b(child);
    child=0;
    int sum_a=0;
    int sum_b=0;
    REP(i,G[node].size()){
        int v=G[node][i];    
        if(dfs_prev[v]==node){
            cost_a[child]=go(v,1);
            cost_b[child]=go(v,0);
            sum_a+=go(v,1);
            sum_b+=go(v,0);
            child++;            
        }        
    }    
    ans=min(ans,500+sum_a);    
    ans=min(ans,100*(used?0:1)+ sum_b);
    if(used){
        REP(i,child)
            ans=min(ans,100+sum_b-cost_b[i]+cost_a[i]);
        for(int i=0;i<child;i++)for(int j=i+1;j<child;j++)
            ans=min(ans,175+sum_b-cost_b[i]-cost_b[j] + cost_a[i]+cost_a[j]);
    }else
        REP(i,child)
            ans=min(ans,175+sum_b-cost_b[i]+cost_a[i]);
    return ans;            
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
            dfs_prev[i]=-1;
        }
        memset(dp,-1,sizeof dp);        
        REP(i,N-1){
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        dfs(0);
        ans=go(0,1);
        printf("$%d\n",ans);   
   }     
   return 0;      
}
