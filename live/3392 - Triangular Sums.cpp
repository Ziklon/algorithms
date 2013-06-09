#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   int T,N;
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        ll ans=0;
        REP(u,N){
            int v=u+2;
            int d=(v*(v+1))/2;
            ans+=((u+1)*(d));
        }
        printf("%d %d %lld\n",t+1,N,ans);
   }
   return 0;      
}

