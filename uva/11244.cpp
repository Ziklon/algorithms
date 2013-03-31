#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
string adj[105];
bool vis[105][105];
int dx[]={0,0,1,-1,1,-1,-1,1},r,c;
int dy[]={1,-1,0,0,1,-1,1,-1};
int dfs(int x, int y){
      vis[x][y]=1;
      int dev=1;
      for(int i=0;i<8;i++){
         int X=x+dx[i];
         int Y=y+dy[i];
         if(X<r && Y<c && X>=0 && Y>=0 && !vis[X][Y] && adj[X][Y]=='*')
            dev+=dfs(X,Y);
      }
      return dev;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>r>>c && r && c){
    fill(vis,0);  
    for(int i=0;i<r;i++)cin>>adj[i];
    int dev=0;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++){
      if(adj[i][j]=='*' && !vis[i][j] && dfs(i,j)==1)
         dev++;
    }
    printf("%d\n",dev);  
  }
  return 0;
}
