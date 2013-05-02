#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 1000005

bool sieve[MAXN];
int P[MAXN];
int ans[MAXN];
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   int idx=0,N;
   REP(i,MAXN){
        sieve[i]=0;
        P[i]=0;
        ans[i]=0;
   }
   
   for(int i=2;i*i<MAXN;i++)if(sieve[i]==0)for(int j=i*i;j<MAXN;j+=i)sieve[j]=1;
   for(int i=2;i<MAXN;i++)if(sieve[i]==0)P[idx++]=i;
   
   int sum=0;
   for(int i=2;i<MAXN;i++){       
      int tmp=i;
      for(int i=0;P[i]*P[i]<=tmp;i++){          
          while((tmp%P[i])==0){
             sum++;
             tmp/=P[i];
          }         
      } 
      if(tmp>1)sum++;        
      ans[i]=sum;    
   }
   //for(int i=2;i<MAXN;i++)if(sieve[i]==0)P[idx++]=i;
   
   
   while(scanf("%d",&N)==1){
        printf("%d\n",ans[N]);      
    
   }    
   
   return 0;      
}

