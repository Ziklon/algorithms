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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int M,N;

int di[8]={0,0,1,-1,1,-1,-1,1};
int dj[8]={1,-1,0,0,1,1,-1,-1};

char board[101][101];
bool visit[101][101];

void dfs(int x, int y){
  visit[x][y]=1;
  for(int i=0;i<8;i++){
    int X=x+di[i];
    int Y=y+dj[i];
    if(X>=0&& X<M && Y>=0 && Y<N && !visit[X][Y] && board[X][Y]=='@')
      dfs(X,Y);
  }
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int m,n;
  while(cin>>m>>n){
    if(!m)break;
    M=m;N=n;
    int dev=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>board[i][j];
    mem(visit,0);
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        if(board[i][j]=='@' && !visit[i][j]){
          dev++;
          dfs(i,j);
        }
   cout<<dev<<endl;
  } 
  return 0;
}

