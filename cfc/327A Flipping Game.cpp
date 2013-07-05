#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

int A[110],N;
int main(){
    scanf("%d",&N);
    REP(i,N)scanf("%d",&A[i]);
    int ans=0;
    REP(i,N)REP(j,N)if(j>=i){
        REP(k,j-i+1)A[i+k]^=1;
        int tmp=0;
        REP(k,N)if(A[k]==1)tmp+=1;
        ans=max(ans,tmp);
        REP(k,j-i+1)A[i+k]^=1;
    }
    printf("%d\n",ans);
    return 0;      
}
