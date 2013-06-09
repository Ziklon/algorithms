#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define MAXN 10005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> G[MAXN];
int root[MAXN][15],dist[MAXN],lvl[MAXN],pi[MAXN];

void dfs(int u, int prev, int depth){
    lvl[u]=depth;
    REP(i,G[u].size()){
        int v=G[u][i].first;
        if(v!=prev){
            dist[v]=dist[u]+G[u][i].second;
            pi[v]=u;
            dfs(v,u,depth+1);            
        }
    }    
}

void calcRoot(int n){
    memset(root,-1,sizeof root);
    for(int i=1;i<=n;i++)root[i][0]=pi[i];
    
    for(int j=1;1<<j<=n;j++)
        for(int i=1;i<=n;i++)
            if(root[i][j-1]!=-1)
                root[i][j]=root[root[i][j-1]][j-1];
}

int lca(int p, int q){
    if(lvl[p]<lvl[q])swap(p,q);
    int log;
    for(log=1;1<<log<=lvl[p];log++);
    log--;
    for(int i=log;i>=0;i--)
        if(lvl[p]-(1<<i)>=lvl[q])
            p=root[p][i];
    if(p==q)return p;
    
    for(int i=log;i>=0;i--)
        if(root[p][i]!=-1 && root[p][i]!=root[q][i])
            p=root[p][i],q=root[q][i];
    return pi[p];
}

int find (int p, int k){
    int i,log;
    for(log=1;1<<log<=lvl[p];log++);log--;
    
    for(i=log;i>=0;i--)
        if(lvl[p]-(1<<i)>=k)
            p=root[p][i];
    return p;
}


char command[120];
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   int N,T;
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        REP(i,MAXN){
            G[i].clear();
            lvl[i]=dist[i]=pi[i]=0;
        }
        REP(i,N){
            int x,y,d;
            scanf("%d %d %d\n",&x,&y,&d);
            G[x].push_back(make_pair(y,d));
            G[y].push_back(make_pair(x,d));
        }
        dfs(1,-1,0);
        calcRoot(N);
        
        while(1){
            scanf("%s",command);
            if(command[1]=='O')break;            
            int st,en,u,k;
            ll ans=-1;
            scanf("%d %d\n",&st,&en);
            u=lca(en,st);
            if(command[0]=='D'){                
                ans=(dist[st]+dist[en] - 2*dist[u]);                
            }else{
                scanf("%d",&k);
                if(lvl[st]-lvl[u]+1>=k)ans=find(st,lvl[st]-k+1);
                else ans=find(en,2*lvl[u]+k-lvl[st]-1);
            }
            scanf("\n");
            printf("%lld\n",ans);
        }
        
   }
   return 0;      
}

