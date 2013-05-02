#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 46345
int N;
typedef long long ll; 

bool sieve[MAXN];
int P[MAXN];


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   memset(sieve,0,sizeof sieve);
   for(int i=2;i*i<=MAXN;i++)if(sieve[i]==0)for(int j=i*i;j<MAXN;j+=i)sieve[j]=1;
   
   int tam=0;
   REP(i,MAXN)if(i>=2 && sieve[i]==0)P[tam++]=i;
   
   while(scanf("%d",&N)==1){
        int ans=N;
        int R=(int)sqrt(N);
        int divs=0;
        int tmp=N;
        for(int i=1;i<=R;i++)if(N%i==0){
           divs++;
           if(i*i!=N)divs++;            
        }    
        ll PF=2;
        int idx=0;
        int phi=N;
        while(PF*PF<=N && N!=1 && idx<tam){                
            if(N%PF==0)phi-=phi/PF;
            while(N%PF==0)N/=PF;
            PF=P[++idx];                
        }
        if(N!=1)phi-=(phi/N);
        ans-=(divs+phi-1);
        printf("%d\n",ans);  
    }     
      
   return 0;      
}

