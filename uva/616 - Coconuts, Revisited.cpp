#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
ll N;


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(cin>>N){
        if(N<0)break;
        int ans=-1;
        for(int  i=2;i<=50;i++){
            ll val=N;
            bool can=1;
            for(int j=0;j<i;j++){
                --val;
                if((val%i)!=0){
                    can=0;
                    break;
                }
                val=val-(val/i);
            }
            if(val%i)can=0;    
            if(can)ans=i;        
        }        
        if(ans>0)printf("%lld coconuts, %d people and 1 monkey\n",N,ans);
        else printf("%lld coconuts, no solution\n",N);
   }   
   
   return 0;      
}

