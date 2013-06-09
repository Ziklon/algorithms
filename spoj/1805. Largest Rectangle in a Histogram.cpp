#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
#define MAXN 100005
int M[MAXN][17],A[MAXN],N,L[MAXN],R;


inline int RMQ(int i, int j){
    int k=L[j-i+1];    
    if (A[M[i][k]] <= A[M[j - (1 << k) + 1][k]])
        return M[i][k];
    return M[j - (1 << k) + 1][k];    
}
ll ans,tmp;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   
   REP(i,MAXN)if(i>=1)L[i]=(int)log2(i);
   
   while(scanf("%d",&N)==1){
        if(N==0)break;
        REP(i,N)scanf("%d",&A[i]);
        
        REP(i,N)M[i][0]=i;
        
        for(int j=1;1<<j<=N;j++)
            for(int i=0;i+(1<<j)-1<N;i++)
                if(A[M[i][j-1]]<A[M[i+(1<<(j-1))][j-1]])
                    M[i][j]=M[i][j-1];
                else
                    M[i][j]=M[i+(1<<(j-1))][j-1];
        
        ans=0;
        REP(i,N){
            int low=i;
            int hih=N;
            tmp=0;
            while(hih-low>1){
                int mid=(low+hih)>>1;
                if(A[RMQ(i,mid)]>=A[i])
                    low=mid;
                else
                    hih=mid;
            }
            tmp+=(low-i+1);
            low=0;
            hih=i;
            while(hih-low>1){
                int mid=(low+hih)>>1;
                if(A[RMQ(mid,i)]>=A[i])
                    hih=mid;
                else
                    low=mid;
            }
            tmp=tmp+(i-hih);                    
            ans=max(ans,tmp*(A[i]));        
        }
        printf("%lld\n",ans);       
        
   }
   return 0;      
}

