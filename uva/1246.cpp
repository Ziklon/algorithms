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
#define MAX 6000000
int S[MAX+4];

bool isPrime(int x){
  if(x<2)return 0;
  for(int i=2;i*i<=x;i++)
    if(x%i==0)
      return 0;
  return 1;
}

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int T,x,y;
   fill(S,0);
   for(int i=1;i<=MAX;i++)
      for(int j=i;j<=MAX;j+=i)
        S[j]++; 
    scanf("%d\n",&T);    
    REP(i,0,T){
      scanf("%d %d\n",&x,&y);
    
      
      bool ok=0;
      for(int j=x;j<=y;j++)
        if(isPrime(S[j])){
          if(!ok){
            printf("%d",j);
            ok=1;
          }
          else
            printf(" %d",j);
        }
      if(!ok)printf("-1");
      printf("\n");            
    }
        
   //system("pause");
   return 0;
}
