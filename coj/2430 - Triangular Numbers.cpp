#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef unsigned long long ull;
ull n;



int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
   #endif
   //ull a=16000000000000000000LL;
   //cout<<a<<endl;
   while(cin>>n && n!=0){
        
        bool found=0;
        ull m=(ull)(sqrt(2)*sqrt(n)),t,a,b;
        
        for(int i=-20;i<=20;i++){
            a=m+i+0ULL;
            b=m+i+1ULL;
            if(b&1)a>>=1;
            else b>>=1;
            t=(a*b);
            if(t==n)found=1;
        }
        if(found)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;                
    
   }
   return 0;      
}

