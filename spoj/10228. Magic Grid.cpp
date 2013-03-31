#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 501
int T,R,C,S[MAXN][MAXN],dp[MAXN][MAXN];
int dx[]={0,-1};
int dy[]={-1,0};
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   scanf("%d",&T);
   while(T--){
        scanf("%d %d",&R,&C);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&S[i][j]);
        
        int low=0;
        int hih=1<<20;                
        while(hih-low>1){
            int mid=(low+hih)>>1;
            memset(dp,0,sizeof dp);
            dp[0][0]=mid+S[0][0];
            for(int i=0;i<R;i++)
              for(int j=0;j<C;j++){
                for(int k=0;k<2;k++){
                    int x=dx[k]+i;
                    int y=dy[k]+j;
                    if(min(x,y)>=0 && x<R && y<C && dp[x][y]>0)
                        dp[i][j]=max(dp[i][j],dp[x][y]+S[i][j]);
                }    
            }
            if(dp[R-1][C-1]>0)
                hih=mid;
            else
                low=mid;
        }
        printf("%d\n",hih);
   }   
   return 0;      
}
