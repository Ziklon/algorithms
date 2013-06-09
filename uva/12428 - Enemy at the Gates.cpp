#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
ll N,M;
int T;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   scanf("%d",&T);
   while(T--){
        scanf("%lld %lld",&N,&M);
        if(M<N)printf("%lld\n",M);
        else{
            ll low=1,hih=N;
            while(low<hih){
                ll mid=(low+hih)>>1;
                ll need=(mid*(mid-1LL))/2LL;
                if(need+N-mid<M)
                    low=mid+1;
                else
                    hih=mid;
            }
            printf("%lld\n",N-low);
        }
   }
   return 0;      
}


