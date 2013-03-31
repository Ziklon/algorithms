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
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int dat[11][11],n,cn;
int sum(int x, int r){
   int dev=0,k;
   for(int i=x;i<x+r;i++)dev+=dat[x][i];
   for(int i=x+1;i<x+r;i++)dev+=dat[i][x];
   k=n-x-1;
   for(int i=x+1;i<x+r;i++)dev+=dat[k][i];
   for(int i=x+1;i<x+r-1;i++)dev+=dat[i][k];   
   return dev;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  cn=1;
  while(cin>>n && n){
      for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>dat[i][j];
      
      printf("Case %d:",cn);
      for(int i=0;i*2<n;i++) printf(" %d",sum(i,n-(i*2)));
      printf("\n");
      cn++;
  }   
  return 0;
}
