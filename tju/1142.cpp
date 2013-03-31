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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define EPS 1e-6
using namespace std;
int P[220],T;
double D[220][220];
struct point{
  int x, y;
  point(){}
  point(int _x, int _y){
      x=_x;
      y=_y;
  } 
}Ps[210];

double getDis(int x, int y){
   return hypot(Ps[x].x-Ps[y].x,Ps[x].y-Ps[y].y);
}
bool vis[220];
void dfs(int x, double val){
   vis[x]=1;
   REP(i,0,T){
      if(getDis(x,i)<=val && !vis[i]){
         dfs(i,val);
      }
   }
   return;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,y,a,b,N=1,p,q;
    double ans;
    while(cin>>T && T){
      ans=0;
      REP(i,0,T)
         cin>>Ps[i].x>>Ps[i].y;
      double low=0,hih=1e+6;
      double val;
      while(hih-low>EPS){
         val=(low+hih)/2.0;
         fill(vis,0);
         dfs(0,val);
         if(vis[1])
            hih=val;
         else
            low=val;
      }      
      printf("Scenario #%d\n",N++);
      printf("Frog Distance = %0.3f\n",low);
      printf("\n");      
      
    }  
    //system("pause");
    return 0;
}
