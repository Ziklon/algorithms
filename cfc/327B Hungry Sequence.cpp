#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define MAXN 10000000
using namespace std;

bool sieve[MAXN];
int idx=0;
int A[MAXN],N;
int main(){
    memset(sieve,0,sizeof sieve);
    for(int i=2;i*i<MAXN;i++)if(sieve[i]==0)
        for(int j=i*i;j<MAXN;j+=i)sieve[j]=1;
    
    REP(i,MAXN)if(i>=2 && sieve[i]==0)A[idx++]=i;
    
    scanf("%d",&N);
    REP(i,N){
        if(i!=0)printf(" ");
        printf("%d",A[i]);        
    }
    printf("\n");   
    return 0;      
}
