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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int T,N,M;
int G[1001][1001];
int dis[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node{
   int x,y;
   node(int _x, int _y){
      x=_x;
      y=_y;
   }
   
   bool operator < (node q)const{
      return dis[q.x][q.y]<dis[x][y];
   }
};
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   T=GI;
   //929
   for(int i=0;i<T;i++){
      N=GI;
      M=GI;   
      for(int x=0;x<N;x++)
         for(int y=0;y<M;y++){
            scanf("%d",&G[x][y]);
            dis[x][y]=1<<29;
         }
      priority_queue<node>Q;
      Q.push(node(0,0));
      dis[0][0]=G[0][0];
      while(!Q.empty()){
         node cur=Q.top();
         Q.pop();
         for(int x=0;x<4;x++){
            int X=dx[x]+cur.x;
            int Y=dy[x]+cur.y;
            if(X>=0 && Y>=0 && X<N && Y<M){
               if(dis[X][Y]>dis[cur.x][cur.y]+G[X][Y]){
                  dis[X][Y]=dis[cur.x][cur.y]+G[X][Y];
                  Q.push(node(X,Y));
               }
            }
         }
      }
      printf("%d\n",dis[N-1][M-1]);      
   }
   return 0;
}
