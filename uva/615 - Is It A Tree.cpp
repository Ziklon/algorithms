#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>

#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int T=1;

vector<vector<int> > G;
vector<bool> vis;
bool found;
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v]==0)dfs(v);
        else found =1;
    }
}
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   int x,y;
   
   while(scanf("%d %d",&x,&y)==2){
        if(x<0 && y<0)break;
        found=0;        
        map<int,int> M;
        set<int> S;
        if(x==0 && y==0){
            printf("Case %d is a tree.\n",T);
            T++;
            continue;
        }        
        vector<pair<int,int> >v;
        if(M.count(x)==0)M[x]=M.size();
        if(M.count(y)==0)M[y]=M.size();
        S.insert(y);        
        v.push_back(make_pair(x,y));
        while(scanf("%d %d",&x,&y)==2){
            if(x==y && x==0)break;
            if(M.count(x)==0)M[x]=M.size();
            if(M.count(y)==0)M[y]=M.size();
            S.insert(y);
            v.push_back(make_pair(x,y));
        }
        int root=-1;
        int cntRoots=0;
        G.clear();
        G.resize(M.size()+10);        
        vis.assign(M.size()+10,0);
        foreach(M,it){
            x=(it)->first;
            if(S.count(x)==0){
                cntRoots++;
                root=M[x];
            }
        }
        for(int i=0;i<v.size();i++){
            x=M[v[i].first];
            y=M[v[i].second];
            G[x].push_back(y);            
        }
        if(root>-1)dfs(root);  
        
        for(int i=1;i<=M.size();i++)if(!vis[i])found=1;
              
        if(found==0 && cntRoots==1 && root>-1)printf("Case %d is a tree.\n",T);
        else printf("Case %d is not a tree.\n",T);
        T++;
   }
   return 0;      
}
