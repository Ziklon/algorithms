#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int N;
long long  ans,A,B,X;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(scanf("%d",&N)==1){
        X=((N+1LL)/2);
        X=X*X;
        A=X;
        B=X-3;
        A*=A;
        B*=B;
        ans=A-B;
        if(N==1)ans=1;
        printf("%lld\n",ans);
        
   }
   return 0;      
}

