#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 10000001
bool sieve[MAXN];
int F[MAXN];
long long G[MAXN];
int T,N;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   for(int i=0;i<MAXN;i++){
        F[i]=MAXN;
        sieve[i]=0;
   }
   for(int i=2;i<=3162;i++)
        if(sieve[i]==0)
            for(int j=i*i;j<MAXN;j+=i){
                sieve[j]=1;
                F[j]=min(F[j],i);
            }
   G[0]=G[1]=0;
   for(int i=2;i<MAXN;i++){
        G[i]=G[i-1]+min(i,F[i]);
   }
   scanf("%d",&T);
   for(int i=0;i<T;i++){
        scanf("%d",&N);
        printf("%lld\n",G[N]);    
   }
   return 0;      
}
