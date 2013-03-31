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
    string a,b;
    while(cin>>tot>>N){
      map<string,int>M;
      REP(i,0,N){
         cin>>a;
         M[a]=i;
         make(i);
      }
      cin>>C;      
      vector<node> v;
      double ans=0,aux;
      int tt=1;
      REP(i,0,C){
         cin>>a>>b>>aux;         
         v.push_back(node(M[a],M[b],aux));
      }
      sort(all(v));
      REP(i,0,C){
         if(tt==N)break;
         node cur=v[i];
         if(FIND(cur.x)!=FIND(cur.y)){
            UNION(cur.x,cur.y);
            ans+=cur.d;
            tt++;
         }
      
      }
      if(ans<=tot && tt==N)
         printf("Need %0.1f miles of cable\n",ans);
      else
         printf("Not enough cable\n");
         
    }   
    //system("pause");
    return 0;
}
