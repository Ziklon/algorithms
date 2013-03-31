/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int n,p,i,x,y,d,j,ans;

struct node{
   int p,d;
   node(){}
   node(int _p, int _d){
      p=_p;
      d=_d;      
   }
};
struct edge{
   int x,y,d;
   edge(){};
   edge(int _x, int _y, int _d){
      x=_x;
      y=_y;
      d=_d;
   }
};
vector<node>G[1005];
bool vis[1005];
int dfs(int x, int d){
   vis[x]=1;
   if(G[x].sz==0)return d;
   int ans=-1;
   REP(j,0,G[x].sz){
      if(!vis[G[x][j].p] && G[x][j].d<=d){
         ans=max(ans,dfs(G[x][j].p,min(d,G[x][j])))
      }   
   }
   return ans;   
}


int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d %d\n",&n,&p);
    vector<edge> Adj;
    REP(i,0,p){
      scan("%d %d %d",&x,&y,&d);
      G[x].push_back(node(y,d));
      Adj.push_back(edge(x,y));
    }
    REP(i,0,p){
      edge cur=Adj[i];
      vis[edge.x]=1;
      ans=dfs(edge.y,edge.d);
      if(ans>0)
         printf("%d %d ")
    }
    
    
    //system("pause");
    return 0;
}
