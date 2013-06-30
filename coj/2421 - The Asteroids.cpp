#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
int T;
int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   
   while(scanf("%d",&T)==1 && T>0){
        int xt,yt,x,y,r;
        scanf("%d %d",&xt,&yt);
        int idx=0;
        double dist=1e+20;
        
        REP(i,T){
            scanf("%d %d %d",&x,&y,&r);
            double tmp=max(hypot(x-xt,yt-y)-r,0.0);
            if(tmp<dist){
                dist=tmp;
                idx=i+1;
            }
        }
        printf("%d\n",idx);
    
   }
   
   return 0;      
}

