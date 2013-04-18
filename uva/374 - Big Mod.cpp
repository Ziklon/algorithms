#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;

ll B,P,M,ans;

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(cin>>B>>P>>M){
        ans=1;
        while(P){
            if(P&1)ans=(ans*B)%M;
            P>>=1;
            B=(B*B)%M;
        }
        cout<<ans<<endl;
   }
   return 0;      
}

