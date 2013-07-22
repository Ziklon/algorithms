#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
string  B[20];
bool can[20][20];

int N,M;
int main(){
    cin>>N>>M;
    REP(i,N)cin>>B[i];
    int ans=0;
    memset(can,0,sizeof can);
    REP(i,N){
        if(B[i].find("S")==-1){
            REP(j,M)can[i][j]=1;
        }
    }
    
    REP(j,M){
        bool ok=1;
        REP(i,N)if(B[i][j]=='S')ok=0;
        if(ok){
            REP(i,N)can[i][j]=1;
        }
    }
    REP(i,N)REP(j,M)if(can[i][j])ans+=1;

    cout<<ans<<endl;
   return 0;      
}
