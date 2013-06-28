#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define MAXN 1<<20
using namespace std;
typedef long long ll;
bool sieve[1<<20];
int P[1<<20],a,b,ans;
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   REP(i,1<<20){
        sieve[i]=0;
        P[i]=0;
   }
   for(int i=2;i*i<MAXN;i++)
        if(sieve[i]==0)
            for(int j=i*i;j<MAXN;j+=i)sieve[j]=1;
    
   for(int i=2;i<MAXN;i++){
        P[i]=P[i-1];
        if(sieve[i]==0)P[i]+=1;    
   }
    
    
    while(scanf("%d %d",&a,&b)==2){
        if(a==b && a==0)break;
        
        ans=(P[b]-P[a-1]);
        printf("%d\n",ans);        
        
    }
    
   
   return 0;      
}

