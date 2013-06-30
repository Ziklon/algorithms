#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;

int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   int T;
   string M,N;
   cin>>T;
   while(T--){
        cin>>M>>N;
        if(M.find(N)!=-1 && M.find("T")!=-1)
            puts("Y");
        else
            puts("N");
    
   }
   return 0;      
}

