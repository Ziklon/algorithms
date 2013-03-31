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
string adj[10];
bool vis[10][10];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int dfs(int x, int y, char c, char r){
    if(adj[x][y]==r)return -(1<<20);
    if(adj[x][y]==c)return 0;
    vis[x][y]=1;
    int dev=1;
    for(int m=0;m<4;m++){
      int X=x+dx[m];
      int Y=y+dy[m];
      if(X>=0 && Y>=0 && X<9 && Y<9 && !vis[X][Y])
         dev=dev+dfs(X,Y,c,r);
    }
    return dev;  
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n,aux;
  cin>>n;
  while(n--){
      fill(vis,0);
      for(int i=0;i<9;i++)cin>>adj[i];
      int X=0,Y=0;
      for(int i=0;i<9;i++)for(int j=0;j<9;j++){
          X+=(adj[i][j]=='X');  
          Y+=(adj[i][j]=='O');
      }
      for(int i=0;i<9;i++)for(int j=0;j<9;j++){
         if(adj[i][j]=='.' && !vis[i][j]){
           aux=dfs(i,j,'X','O');
           if(aux>0)
               X+=aux; 
         }   
      }
      fill(vis,0);
      for(int i=0;i<9;i++)for(int j=0;j<9;j++){
         if(adj[i][j]=='.' && !vis[i][j]){
           aux=dfs(i,j,'O','X');
           if(aux>0)
               Y+=aux; 
         }   
      }
      printf("Black %d White %d\n",X,Y);     
      
  }   
  return 0;
}
