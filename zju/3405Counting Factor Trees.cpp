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
ll dp[1<<20];
int N;


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   memset(dp,-1,sizeof dp);
   while(scanf("%d",&N)==1){        
       for(int i=2;i*i<=N;i++)if(N%i==0)cout<<i<<" "<<(N/i)<<endl;
       cout<<endl; 
   }
   return 0;      
}
