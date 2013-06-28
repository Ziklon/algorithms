#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
ll n,low,hih,mid;
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   while(scanf("%lld",&n)==1 && n>0){
        low=0;hih=1<<20;
        while(hih-low>1){
            mid=(hih+low)>>1;
            if(mid*mid>=n)hih=mid;
            else low=mid;            
        }
        printf("%lld\n",hih);
    
   }
   return 0;      
}


