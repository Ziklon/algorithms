#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
#define first fst
#define second snd
#define sz size()
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;

ll mod_expo(ll a, ll b, ll m){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
ll x,y,m;
int T;
int main(){
    cin>>T;
    while(T--){
        cin>>x>>y>>m;
        cout<<mod_expo(x,y,m)<<endl;
    }
    return 0;
}

