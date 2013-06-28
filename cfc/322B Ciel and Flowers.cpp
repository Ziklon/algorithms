#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

int dp[51][51][51];

int go(int r, int g, int b){
    
    int& ref=dp[r][g][b];
    if(ref!=-1)return ref;
    ref=0;
    if(r>=1 && g>=1 && b>=1) ref=max(ref,go(r-1,g-1,b-1)+1);
    if(r>=3)ref=max(ref,go(r-3,g,b)+1);
    if(g>=3)ref=max(ref,go(r,g-3,b)+1);
    if(b>=3)ref=max(ref,go(r,g,b-3)+1);
    return ref;
}

int main(){
    memset(dp,-1,sizeof dp);
    vector<int> v(3);
    REP(i,3)scanf("%d",&v[i]);
    int ans=0;
    
    REP(i,3){
        if(v[i]>=48){
            ans+=(v[i]/48)*16;
            v[i]%=48;            
        }    
    }
    ans+=go(v[0],v[1],v[2]);    
    
    
    printf("%d\n",ans);      
    return 0;      
}
