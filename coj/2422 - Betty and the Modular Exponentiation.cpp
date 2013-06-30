#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

#define MOD 1000000000LL
using namespace std;
typedef long long ll;

ll exp_mod(ll a, ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int T;
ll a,b;
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%lld %lld",&a,&b);
        printf("%d\n",exp_mod(a,b));
   }
   return 0;      
}

