#include <cstdio>
#define max(a,b) a>b?a:b
int N,i,j,ans,T;int d[1000][1000];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        ans=0;
        for(i=0;i<N;i++)for(j=0;j<=i;j++){
            scanf("%d",&d[i][j]);
            if(i>0)if(j>0)d[i][j]+=max(d[i-1][j-1],d[i-1][j]);
            else d[i][j]+=d[i-1][j];
            ans=max(d[i][j],ans);
        }
        printf("%d\n",ans);
    }
}
