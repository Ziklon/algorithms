#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct flow_graph{    
    int MAX_V,E,M,source,sink;
    int *adj, *cap, *last, *next;                
    flow_graph(){}
    flow_graph(int _V,int MAX_E){
        MAX_V=_V;
        adj=new int[2*MAX_E];next=new int[2*MAX_E];cap=new int[2*MAX_E];
        last=new int[2*MAX_E];
                            
    }
    void clear(){
        memset(last,-1,sizeof last);
        E=0;        
    }
    void add_edge(int u, int v, int uv, int vu=0){
        adj[E]=v;cap[E]=uv;next[E]=last[u];last[u]=E++;
        adj[E]=u;cap[E]=vu;next[E]=last[v];last[v]=E++;                      
    }        
    int dfs(int u, int flow){
        if(u==sink)return flow;
        for(int& e=last[e];e !=-1;e=next[e]){
            if(cap[e]>0){
                int ret=dfs(adj[e],min(flow,cap[e]));
                if(ret>0){
                    cap[e]-=ret;
                    cap[e^1]+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }    
    int max_flow(int s, int t){
        sink=t;source=s;
        int flow=0;
        while(1){
            int tmp=dfs(source,1<<20);
            if(tmp==0)break;
            flow+=tmp;
        }
        return flow;
    }    
}G(110,5000);

int N,s,t,c,a,b,k,Z=1,ans;

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(scanf("%d",&N)==1 && N){
        scanf("%d %d %d",&s,&t,&c);s--;t--;
        G.clear();
         
        for(int i=0;i<c;i++){
            scanf("%d %d %d",&a,&b,&k);a--;b--;
            G.add_edge(a,b,k,k);    
        }
        printf("Network %d\n",Z++);
        ans=G.max_flow(s,t);
        printf("The bandwidth is %d.\n",ans);        
        printf("\n");
   }
   return 0;      
}
