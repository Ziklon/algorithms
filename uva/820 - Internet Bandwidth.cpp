#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define MAXN 105
int N,s,t,c,a,b,k,f,ans;

int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int prev[MAXN];

vector<vector<int> > Adj;
 
int Z=1;


void augment( int v, int minEdge, int& s){
    if(v==s){
        f=minEdge;
        return;
    }else{
        augment(prev[v],min(cap[prev[v]][v]-flow[prev[v]][v],minEdge),s );
        flow[v][prev[v]]-=f;
        flow[prev[v]][v]+=f;        
    }
}

bool bfs(int& s, int& t){
    memset(prev,-1,sizeof prev);
    queue<int> Q;
    Q.push(s);
    prev[s]=-2;
    bool found=0;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(u==t){
            found=1;
            break;
        }
        for(int i=0;i<Adj[u].size();i++){
            if(flow[u][Adj[u][i]]< cap[u][Adj[u][i]] && prev[Adj[u][i]]==-1){
                prev[Adj[u][i]]=u;
                Q.push(Adj[u][i]);
            }            
        }   
    }
    if(!found)return 0;    
    f=0;
    augment(t,1<<20,s);    
    return 1;
}


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(scanf("%d",&N)==1 && N){
        scanf("%d %d %d",&s,&t,&c);s--;t--;
        
        memset(cap,0,sizeof cap);
        memset(flow,0,sizeof flow);
        Adj.clear();
        Adj.resize(N);                                
        for(int i=0;i<c;i++){
            scanf("%d %d %d",&a,&b,&k);
            if(cap[a-1][b-1]==0){
                Adj[a-1].push_back(b-1);
                Adj[b-1].push_back(a-1);              
            }            
            cap[a-1][b-1]+=k;
            cap[b-1][a-1]+=k;
        }
        printf("Network %d\n",Z++);
        ans=0;
        while(bfs(s,t))ans+=f;
        printf("The bandwidth is %d.\n",ans);        
        printf("\n");
   }
   return 0;      
}
