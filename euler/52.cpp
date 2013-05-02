#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   
   int A[6];
   vector<int> v,u;
   for(int i=1000;i<=1000000000;i++){        
        int tmp=i;
        v.clear();
        while(tmp){
            v.push_back(tmp%10);
            tmp/=10;
        }        
        sort(v.begin(),v.end());
        bool ok=1;
        for(int j=2;j<=6;j++){
            int tmp=j*i;
            u.clear();
            while(tmp){
                u.push_back(tmp%10);
                tmp/=10;
            }
            sort(u.begin(),u.end());
            if(u!=v)ok=0;
        }
        if(ok){
            cout<<i<<endl;
            break;
        }        
        
   }
   
   return 0;      
}

