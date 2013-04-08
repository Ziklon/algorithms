#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

long long F[12];

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   F[0]=F[1]=1;
   for(int i=2;i<=10;i++)F[i]=F[i-1]*i;
   
   int T,N,x;
   scanf("%d",&T);
   REP(i,T){
       scanf("%d",&N);
       int odds=0;
       int even=0;
       int zero=0;
       REP(j,N){
           scanf("%d",&x);
           if(x==0)zero=1;
           if(x&1)odds++;
           else even++; 
       }
       long long ans=F[N-1];
       if(zero)ans-=F[max(N-2,0)];
       ans*=odds;
       printf("%lld\n",ans);                
   } 
   return 0;      
}

