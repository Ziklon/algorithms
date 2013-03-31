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
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
int n,k,x,y,c,ans;

vector<pair<int,int> > A[2005];
bool vis[2005];

 int dfs(int x){
  int ans=0;
  vis[x]=1;
  REP(i,0,A[x].sz){
    if(!vis[A[x][i].first])
       ans=max(ans,A[x][i].second + dfs(A[x][i].first));
  }
  return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d\n",&n);
    REP(i,0,n){
      scanf("%d\n",&k);

      REP(j,0,k){
         A[j+1].clear();
         scanf("%d %d %d\n",&x,&y,&c);
         A[x].push_back(make_pair(y,c));
         A[y].push_back(make_pair(x,c));       
      }
      ans=0;
      REP(j,1,k+1){
        fill(vis,0);
        ans=max(ans,dfs(j));        
      }
      printf("%d\n",ans);
      
    }
    //system("pause");
    return 0;
}
