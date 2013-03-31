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
#define MAX 505
using namespace std;
int N,C,i,x,y,d,j,k;
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
   int x, y;
   double d;
   node(){}
   node(int _x, int _y, double _d){
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
    double tot;
    int N,S,P,T;
    scanf("%d",&N);
    REP(i,0,N){
      scanf("%d %d",&S,&P);
      vector<pair<int,int> >vv;
      
      REP(j,0,P){
         scanf("%d %d",&x,&y);
         make(j);
         vv.push_back(make_pair(x,y));
      }
      vector<node> v;
      REP(j,0,P)
         REP(k,j+1,P){
            tot=hypot(vv[j].first-vv[k].first,vv[j].second-vv[k].second);
            v.push_back(node(j,k,tot));
         }
      sort(all(v));
      T=P-S;
      tot=0;
      REP(j,0,v.sz){
         if(T==0)break;
         node cur=v[j];
         if(FIND(cur.x)!=FIND(cur.y)){
            UNION(cur.x,cur.y);
            tot=cur.d;
            T--;
         }
      }
      printf("%0.2f\n",tot);
    } 
    //system("pause");
    return 0;
}
