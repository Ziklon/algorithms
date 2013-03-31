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
string adj[30];
bool vis[30][30];
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
int h,w;
int dfs(int x, int y){
   vis[x][y]=1;
   int dev=1;
   for(int t=0;t<8;t++){
      int X=x+dx[t];
      int Y=y+dy[t];
      if(X>=0 && Y>=0 && X<h && Y<w && !vis[X][Y] && adj[X][Y]=='1')
         dev+=dfs(X,Y);
   }
   return dev;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,dev;
  scanf("%d\n",&n);
  string line;
  //getline(cin,line);
  while(n--){
      h=0;
      dev=0;
      fill(vis,0);
      while(getline(cin,line)){            
         if(line.sz==0)break;
         adj[h++]=line;
      }
      w=adj[0].sz;
      for(int i=0;i<h;i++)
         for(int j=0;j<w;j++)
            if(!vis[i][j] && adj[i][j]=='1')
               dev=max(dev,dfs(i,j));
      printf("%d\n",dev);  
      if(n)
         printf("\n");  
      
  }
  return 0;
}
