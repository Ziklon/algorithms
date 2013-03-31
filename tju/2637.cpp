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
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int W,H;
  while(cin>>W>>H){
    if(W==0 && H==0)break;
    char board[H][W];
    bool visit[H][W];
    int dx=0,dy=0;
    mem(visit,0);
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        cin>>board[i][j];      
        if(board[i][j]=='@'){
          dx=i;
          dy=j;
        }
      }
    }  
    queue<pair<int,int> >Q;
    int dev=1;
    Q.push(mp(dx,dy));
    visit[dx][dy]=1;
    while(!Q.empty()){
      pair<int,int> nodo=Q.front();
      Q.pop();
      int x=nodo.first;
      int y=nodo.second;    
      for(int j=0;j<4;j++){
        int X=x+di[j];
        int Y=y+dj[j];
        if(X>=0 && X<H && Y>=0 && Y<W &&board[X][Y]!='#'&& !visit[X][Y]){
          visit[X][Y]=1;
          dev++;
          Q.push(make_pair(X,Y));
        }
      }
    }
    printf("%d\n",dev);                 
  } 
  return 0;
}

