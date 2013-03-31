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
#define NMAX 100005
#define INF 1<<20
using namespace std;
typedef long long ll;

int N,M,K,x,y;

int nodeCicly;
int dfsCounter;
vector<int> G[NMAX];
vector<int> dfs_low;
vector<int> dfs_num;
vector<int> dfs_parent;
void dfs(int u){
   dfs_low[u]=dfs_num[u]=dfsCounter++;   
   REP(i,G[u].size()){
        int v=G[u][i];
        if(dfs_num[v]==-1){
            dfs_parent[v]=u;
            dfs(v);
        }else{
            if(abs(dfs_num[u]-dfs_num[v])>=K){
               nodeCicly=v;
               return;     
            }          
        }       
   }
       
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d %d %d",&N,&M,&K);
   
   dfs_low.assign(N,INF);
   dfs_num.assign(N,-1);
   dfs_parent.assign(N,-1);
   
   nodeCicly=-1;
   dfsCounter=0;
   
   REP(i,M){
       scanf("%d %d",&x,&y);
       x--;y--;
       G[x].push_back(y);
       G[y].push_back(x);
   }
   
   REP(i,N){
        if(dfs_num[i]==-1 && nodeCicly==-1){
            dfs(i);
        }
   }
   int tmp=nodeCicly;
   set<int> S;
   vector<int> v;
   
   while(1){
        v.push_back(tmp+1);
        tmp=dfs_parent[tmp];    
        if(tmp==-1)break;
   }
   
   cout<<v.size()<<endl;
   REP(i,v.size()){
       if(i)cout<<" ";
        cout<<v[i];
   }        
   return 0;      
}
