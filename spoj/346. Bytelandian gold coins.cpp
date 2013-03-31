#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define MAXN 10000000
ll dp[MAXN];
int N;

ll  go(int n){
    if(n<=3)return n;    
    if(n<MAXN){
        ll& ref=dp[n];
        if(ref!=-1)return ref;
        ref=n;        
        ref=max(ref,go(n/2)+go(n/3)+go(n/4));
        return ref;    
    }else{
        return max(n*1LL, go(n/2)+go(n/3)+go(n/4));
    }
}

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   memset(dp,-1,sizeof dp);
      
   while(scanf("%d",&N)==1){
        printf("%lld\n",go(N));    
   }   
   return 0;      
}


