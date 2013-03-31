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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int N,x,y,M,ans;
bool vis[100000+5];
bool C[100000+5];
vector<int> G[100000+5];
void dfs(int x){
   vis[x]=1;
   REP(i,0,G[x].sz){
      if(!vis[G[x][i]])
         dfs(G[x][i]);
   }
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d %d\n",&N,&M)==2){
      fill(vis,0);
      fill(C,0);
      REP(i,0,N+1)G[i].clear();
      REP(i,0,M){
         scanf("%d %d\n",&x,&y);
         G[x].push_back(y);
         G[y].push_back(x);
         C[x]=1;
         C[y]=1;
      }
      ans=0;
      REP(i,1,N+1){
         if(!vis[i] && C[i]){
            ans++;
            dfs(i);
         }
      }
      printf("%d\n",ans);
    }  
    //system("pause");
    return 0;
}
