/*
ID: winftc2
PROG: in.txt
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
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define MAX 60
using namespace std;
int N,C,i,x,y,d;
int P[MAX];
void make(int n){
   P[n]=n;
}
int FIND(int n){
   if(P[n]==n)return n;
   return P[n]=FIND(P[n]);
}

void UNION(int p, int q){
   P[FIND(p)]=FIND(q);
}

struct node{
   int x, y, d;
   node(){}
   node(int _x, int _y, int _d){
      x=_x;
      y=_y;
      d=_d;
   }
   bool operator < (const node q)const{
      return d<q.d;
   }
};

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&N)==1 && N){
      scanf("%d",&C);
      vector<node> v;
      int ans=0,t=0;
      REP(i,0,N+1)make(i);
      REP(i,0,C){
         scanf("%d %d %d",&x,&y,&d);
         v.push_back(node(x,y,d));
      }
      sort(all(v));
      REP(i,0,C){
         if(t==N)break;
         node cur=v[i];
         if(FIND(cur.x)!=FIND(cur.y)){
            UNION(cur.x,cur.y);
            ans+=cur.d;
            t++;
         }
      
      }
      printf("%d\n",ans);
    }   
    //system("pause");
    return 0;
}
