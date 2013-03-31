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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

int N;
int di[4]={-1,1,0,0};
int dj[4]={0,0,1,-1};
int board[101][101];
bool visit[101][101];

long long dfs(int x, int y){
  visit[x][y]=1;
  int dev=board[x][y];
  for(int i=0;i<4;i++){
    int X=x+di[i];
    int Y=y+dj[i];
    if(X>-1 && Y>-1 && X<N && Y<N && !visit[X][Y] && board[X][Y]!=0)
      dev+=dfs(X,Y);
  }
  return dev;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int cs;
  cin>>cs;
  while(cs){
   cin>>N;
   for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
       cin>>board[i][j];
   long long dev=0;
   mem(visit,0);
   for(int i=0;i<N;i++)
     for(int j=0;j<N;j++){
       if(board[i][j]!=0 && !visit[i][j]){
         long long tmp=dfs(i,j);             
         dev=max(dev,tmp);
       }
     }
   cout<<dev<<endl;
   cs--;
  } 
  return 0;
}

