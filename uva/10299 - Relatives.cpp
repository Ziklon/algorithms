#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXP 32622
#define MAXN 1000000000
int N;
bool sieve[MAXP+2];
int A[MAXP+2];
typedef long long ll;

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   memset(sieve,0,sizeof sieve);
   int idx=0;
   for(int i=2;i*i<=MAXP;i++)if(sieve[i]==0){
        for(int j=i*i;j<=MAXP;j+=i)sieve[j]=1;
   }
   REP(i,MAXP)if(i>=2 && sieve[i]==0)A[idx++]=i;
   
   while(scanf("%d",&N)==1 && N>0){        
       int idx=0;
       ll PF=2,ans=N;
       if(N==1)printf("%d\n",0);
       else{
           while(PF*PF<=N && N!=1){
               if(N%PF==0)ans-=ans/PF;
               while(N%PF==0)N/=PF;
               PF=A[++idx];           
           }
           if(N!=1)ans-=ans/N;
           printf("%lld\n",ans);  
       }
   }
   
   
   return 0;      
}

