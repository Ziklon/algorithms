#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;

ll P[55];
bool isPrime(int n){
    if(n<=1)return 0;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   P[0]=1;
   REP(i,51)if(i>=1){
       P[i]=P[i-1];
       if(isPrime(i))P[i]*=i;
   }
   int N;
   while(scanf("%d\n",&N)&&N){
        printf("%lld\n",P[N]);    
   }
   return 0;      
}

