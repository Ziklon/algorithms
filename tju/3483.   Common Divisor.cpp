#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
int T,a,b,c,ans;

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
      scanf("%d %d",&a,&b);
      c=__gcd(a,b);
      set<int> S;
      for(int i=1;i*i<=c;i++){
         if(c%i==0){
            S.insert(i);
            S.insert(c/i);
         }
      }
      printf("%d\n",S.size());
   }
   return 0;      
}
