#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 1<<20
bool P[MAXN];
int D[MAXN];
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   memset(P,0,sizeof P);
   memset(D,0,sizeof D);
   for(int i=2;i*i<MAXN;i++)if(P[i]==0)for(int j=i*i;j<MAXN;j+=i)P[j]=1;
   vector<int> primes;
   REP(i,MAXN)if(i>=2 && P[i]==0)primes.push_back(i);
   
   REP(i,primes.size())for(int j=primes[i];j<MAXN;j+=primes[i])D[j]+=1;
   vector<int> ans;
   REP(i,MAXN)if(D[i]>=3)ans.push_back(i);
   int T,N;
   scanf("%d",&T);
   REP(i,T){
        scanf("%d",&N);
        printf("%d\n",ans[N-1]);
   }  
   return 0;      
}

