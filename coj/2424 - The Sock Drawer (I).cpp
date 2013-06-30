#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
int T,K,C[20];
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&K);
        REP(i,K)scanf("%d",&C[i]);
        sort(C,C+K);
        printf("Case %d: %d %d\n",t+1,K+1,C[K-1]+1);
   }
   return 0;      
}

