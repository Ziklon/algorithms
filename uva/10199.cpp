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
#define INF 1<<20
using namespace std;
typedef long long ll;

int N,C;
string citys[105];
char citya[1<<10],cityb[1<<10];
vector<int> G[101];

int T=1;
int dfsNumerCount;
// 0 -> WHITE , 1 -> GREY, 2 -> BLACK
vector<bool> articulation_point;
vector<int> dfs_low;
vector<int> dfs_num;
vector<int> dfs_parent;

int dfsRoot,rootChildren;

void dfs(int u){    
   dfs_low[u]=dfs_num[u]=dfsNumerCount++;
   REP(i,G[u].size()){
      int v=G[u][i];
      if(dfs_num[v]==-1){
         dfs_parent[v]=u;
         if(u==dfsRoot)rootChildren++;
         dfs(v);          
         if(dfs_low[v]>= dfs_num[u])
                articulation_point[u]=1;
         dfs_low[u]=min(dfs_low[u],dfs_low[v]);
      }else 
        if(v!=dfs_parent[u])
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
   }
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(scanf("%d",&N) && N){
      if(T>1)printf("\n");      
      map<string,int> M;
      articulation_point.assign(N,0);
      dfs_low.assign(N,INF);
      dfs_num.assign(N,-1);     
      dfs_parent.assign(N,-1);
      dfsNumerCount=0;      
      REP(i,101)G[i].clear();
      
      REP(i,N){
         scanf("%s",citya);
         citys[i]=citya;
         M[citya]=i;
      }
      scanf("%d",&C);
      REP(i,C){
         scanf("%s %s",citya,cityb);
         int idxa=M[citya];
         int idxb=M[cityb];
         G[idxa].push_back(idxb);
         G[idxb].push_back(idxa);
      }            
      REP(i,N)if(dfs_num[i]==-1){
          dfsRoot=i;rootChildren=0;
          dfs(i);
          articulation_point[i]=(rootChildren>1);
      }
      vector<string> ans;
      REP(i,N)if(articulation_point[i]==1)ans.push_back(citys[i]);
      
      sort(ans.begin(),ans.end());
      printf("City map #%d: %d camera(s) found\n",T++,ans.size());
      REP(i,ans.size())
         printf("%s\n",ans[i].c_str());
   }
   return 0;
}
