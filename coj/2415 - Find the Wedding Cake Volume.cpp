#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
const double PI = std::atan(1.0)*4;
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   int T,R,H,N;
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        double ans=0;
        REP(i,N){
            scanf("%d %d",&R,&H);
            ans+=(PI*(R*R))*H;
        }        
        printf("%.02f\n",ans);
   
   }
   return 0;      
}

