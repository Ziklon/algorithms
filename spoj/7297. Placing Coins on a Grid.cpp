#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>

#define REP(i,a) for(int i=0;i<int(a);i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

int T,N,M,R;

int dp[40002][201];
ll pascal[202][202];


int go(int r, int f){
    if(f==(N-1)) return r>=1 && r<=M;
    if(r<=0)return 0;
    int& ref=dp[r][f];
    if(ref!=-1)return ref;
    ref=0;
    for(int i=1;i<=M;i++){
        ref=((ref%MOD)+(pascal[M][i]*go(r-i,f+1))%MOD)%MOD;
    }
    return ref;
}



int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   for(int i=0;i<=200;i++)pascal[i][i]=pascal[i][0]=1;
   for(int i=2;i<=200;i++)for(int j=1;j<i;j++)pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
    int ans;
    scanf("%d",&T);
    REP(t,T){
        scanf("%d %d %d",&N,&M,&R);
        if(R<max(M,N))ans=0;
        else if(M==1 || N==1){
            ans=pascal[max(M,N)][R];            
        }else{
            memset(dp,-1,sizeof dp);
            ans=go(R,0);
        }
        printf("%d\n",ans);
    }
    return 0;         
}
