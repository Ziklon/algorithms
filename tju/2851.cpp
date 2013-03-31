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
#define MAX 5005

int dis[MAX];
struct nodo{
  int p,c;
  nodo(int _p, int _c){
    p=_p;
    c=_c;
  }  
};

struct node{
  int x;
  node(){}
  node(int _p){
    x=_p;
  }
  bool operator < (node q)const{
      return dis[q.x]<dis[x];
  }
  
};

vector<nodo> G[MAX];
int N,R;



int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   scanf("%d %d\n",&N,&R);
   int a,b,c;
   REP(i,0,MAX+1)
    dis[i]=1<<30;
   
   REP(i,0,R){
     scanf("%d %d %d\n",&a,&b,&c);
     nodo p(b,c);
     nodo q(a,c);
     G[a].push_back(p);
     G[b].push_back(q);
   }
   priority_queue<node>Q;
   Q.push(node(1));
   dis[1]=0;
   set<int> S;
   while(!Q.empty()){
     node cur=Q.top();
     Q.pop();
     for(int i=0;i<G[cur.x].sz;i++){
        nodo nd=G[cur.x][i];
        if(nd.p==N)
          S.insert(dis[cur.x]+nd.c);
        if(dis[nd.p]>=(dis[cur.x]+nd.c)){
          dis[nd.p]=dis[cur.x]+nd.c;
          Q.push(node(nd.p));
        }
     }
   }
   int ans=0;
   vector<int> v(all(S));
   if(v.sz>=2)ans=v[1];
   cout<<ans<<endl;
   return 0;
}
