#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define MOD 1000000007LL
using namespace std;

string s;
long long P[110];
int N;
long long F(int pos){
    if(pos==-1)return 0;
    if(s[pos]=='1')return (P[pos]+(2LL*F(pos-1)))%MOD;
    return (2LL*F(pos-1))%MOD;
}

int main(){
    P[0]=1;
    REP(i,110)if(i>=1)P[i]=(P[i-1]*4LL)%MOD;
    
    long long ans;
    cin>>s;
    N=s.size();
    reverse(s.begin(),s.end());
    ans=F(N-1);
    cout<<ans<<endl;
    return 0;      
}
