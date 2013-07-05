#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

#define MOD 1000000007LL
#define MAXN 100010
using namespace std;
typedef long long ll;

string s;
ll K;
ll N;

ll mod_expo(ll a, ll n){
    ll ans=1;
    while(n){
        if(n&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return ans;
}

int main(){
    cin>>s>>K;
    N=s.size();
    ll ans=0;
           
    REP(i,N){
        if(s[i]=='0' || s[i]=='5'){
            ans+=mod_expo(2,i);          
            ans%=MOD;
        }
    }
    ll tmp=(mod_expo(2,(K)*N) + MOD-1)%MOD;
    ll div= (mod_expo(2,N)+MOD-1)%MOD;
    tmp=(tmp*mod_expo(div,MOD-2))%MOD;    
    ans=(ans*tmp)%MOD;
    cout<<ans<<endl;
    return 0;      
}
