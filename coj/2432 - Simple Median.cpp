#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define MAXN 100005
using namespace std;
typedef long long ll;
int N;
int A[MAXN];
double ans;
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   
   while(scanf("%d",&N)==1 && N){
        REP(i,N)scanf("%d",&A[i]);
        sort(A,A+N);
        if(N&1)ans=A[N/2];
        else ans=(A[N/2]+A[(N-1)/2])/2.0;
        printf("%.1f\n",ans);
   }
   return 0;      
}

