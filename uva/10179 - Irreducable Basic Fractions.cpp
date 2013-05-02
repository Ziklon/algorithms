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

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   memset(sieve,0,sizeof sieve);
   int idx=0;
   for(int i=2;i<=MAXP;i++)if(sieve[i]==0){
        A[idx++]=i;
        for(int j=i*i;j<=MAXP;j+=i)sieve[j]=1;
   }   
   
   while(scanf("%d",&N)==1 && N>0){
        int ans=N;
        bool ok=0;        
        for(int i=0;i<idx && A[i]<=N;i++){                            
            if(N%A[i]==0){
                while(N%A[i]==0)N/=A[i];        
                ans/=(A[i]);
                ans*=(A[i]-1);                
                ok=1;
            }
        }
        if(N>1){
            ans/=N;
            ans*=(N-1);
        }
        printf("%d\n",ans);    
   }
   
   return 0;      
}

