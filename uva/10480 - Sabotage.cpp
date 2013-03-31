#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
#define MAXN 55
int cap[MAXN][MAXN];
int flow[MAXN][MAXN],N,M,x,y,c;
int prev[MAXN];
bool vis[MAXN];
int cntFlow;

void augment(int t, int minFlow, int s){
    if(t==s){
       cntFlow=minFlow;
       return; 
    }
    augment(prev[t],min(minFlow, cap[prev[t]][t]-flow[prev[t]][t]),s);
    flow[prev[t]][t]+=cntFlow;
    flow[t][prev[t]]-=cntFlow;    
}

int maxFlow(int s, int t){
    memset(prev,-1,sizeof prev);
    queue<int> Q;Q.push(s);
    prev[s]=-2;
    bool found=0;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(u==t){
            found=1;
            break;
        }
        for(int i=1;i<=N;i++){
           if(prev[i]==-1 && cap[u][i]>flow[u][i]){
                prev[i]=u;
                Q.push(i);
           }     
        }    
    }
    if(!found)return 0;
    cntFlow=0;
    augment(t,1<<30,s);
    return 1;   
}

void dfs(int u){
    vis[u]=1;
    for(int i=1;i<=N;i++)
        if(!vis[i] && cap[u][i]>flow[u][i])
            dfs(i);
}
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(scanf("%d %d",&N,&M)==2){
        if(N==M && N==0)break;
        memset(cap,0,sizeof cap);
        memset(flow,0,sizeof flow);
        memset(vis,0,sizeof vis);        
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&x,&y,&c);
            cap[x][y]=c;
            cap[y][x]=c;
        }
        int ansFlow=0;        
        while(maxFlow(1,2))ansFlow+=cntFlow;
        dfs(1);        
        for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
            if(i==j)continue;
            if(cap[i][j]==flow[i][j] && cap[i][j]>0 && vis[i]!=vis[j]){
                printf("%d %d\n",i,j);
            }
        }
        printf("\n");
   }
   return 0;      
}
