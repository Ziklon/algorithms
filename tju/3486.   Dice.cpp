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

int T,n,m;

double dp[101][101];
bool vis[101][101];
double go(int n, int s){
    if(s<0)return 0;
    if(n==0 && s==0)return 1;
    if(n==0 && s>0)return 0;
    
    double& ref=dp[n][s];    
    if(vis[n][s]==1)return ref;
    
    vis[n][s]=1;
    ref=0;
    for(int i=1;i<=6;i++){
       ref+=go(n-1,s-i);  
    }
    ref=ref/6;
    return ref;

}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   memset(vis,0,sizeof vis);
   REP(t,T){
        scanf("%d %d",&n,&m);
        printf("%.2f\n",go(n,m));        
   }
   return 0;      
}
