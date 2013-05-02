#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 1000005
int P[MAXN],N;
bool sieve[MAXN];
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   REP(i,MAXN)P[i]=0,sieve[i]=0;
   
   for(int i=2;i<MAXN;i++)if(sieve[i]==0){        
        for(int j=i;j<MAXN;j+=i){
            sieve[j]=1;
            P[j]++;
        }    
   }   
   while(scanf("%d",&N)==1 && N>0){
       printf("%d : %d\n",N,P[N]);
    
   }
   return 0;      
}

