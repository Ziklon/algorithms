/*
ID: winftc2
PROG: milk
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
#define MAX 20002
struct node{
  int x,c;
  node(){};
  node(int _x, int _y){
    x=_x;
    c=_y;
  }
  bool operator < (node q)const{
      return q.c<c;
  }
};

vector<node> G[MAX];
int dis[MAX];
int oo=200000500;
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    int T,m,n,s,t,x,y,c;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
      scanf("%d %d %d %d\n",&n,&m,&s,&t);
      REP(j,0,n){
        dis[j]=oo;
        G[j].clear();
      }      
      REP(j,0,m){
        scanf("%d %d %d\n",&x,&y,&c);
        G[x].push_back(node(y,c));
        G[y].push_back(node(x,c));
      }
      priority_queue<node> Q;
      Q.push(node(s,0));
      dis[s]=0;
      while(!Q.empty()){
        node cur=Q.top();
        Q.pop();
        REP(j,0,G[cur.x].sz){
          node q=G[cur.x][j];
          if(dis[q.x] > (dis[cur.x]+q.c)){
            dis[q.x]=(dis[cur.x]+q.c);
            Q.push(node(q.x,dis[q.x]));
          }
        }
      }
      printf("Case #%d: ",i+1);
      if(dis[t]!=oo)
        printf("%d\n",dis[t]);
      else
        printf("unreachable\n");
      
    }
    
   //system("pause");
   return 0;
}
