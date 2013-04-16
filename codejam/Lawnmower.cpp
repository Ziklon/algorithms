#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int  T,N,M;

int B[101][101];
bool seen[101][101];
int R1[101];
int C1[101];


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d %d",&N,&M);
        REP(i,N)REP(j,M)scanf("%d",&B[i][j]);
        bool ans=1;
        //memset(seen,0,sizeof seen);
        memset(R1,0,sizeof R1);
        memset(C1,0,sizeof C1);
        
        REP(i,N)REP(j,M)R1[i]=max(R1[i],B[i][j]);        
        REP(j,M)REP(i,N)C1[j]=max(C1[j],B[i][j]);
        
        REP(h,101){
            REP(i,N)REP(j,M)if(B[i][j]==h){
                if(R1[i]>h && C1[j]>h)ans=0;
            }    
        }
        printf("Case #%d: ",t+1);
        printf(ans?"YES":"NO");
        printf("\n");
        
   }
   return 0;      
}

