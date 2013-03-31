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
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
int W,H;
char board[21][21];
bool visit[21][21];
int dev=0;
int dfs(int x,int y){
 visit[x][y]=1;
 for(int i=0;i<4;i++){
   int X=x+di[i];
   int Y=y+dj[i];
   if(X>=0 && X<H && Y>=0 && Y<W && board[X][Y]!='#' && !visit[X][Y]){    
     dfs(X,Y);
     dev++;  
   } 
  }
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int dx,dy;
  mem(visit,0);
  while(cin>>W>>H){
    mem(visit,0);            
    if(W==0&&H==0)break;            
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++){
        cin>>board[i][j];      
        if(board[i][j]=='@'){
         dx=i;
         dy=j;
        }
      } 
   dev=1;
   dfs(dx,dy);
   printf("%d\n",dev); 
  } 
  return 0;
}

