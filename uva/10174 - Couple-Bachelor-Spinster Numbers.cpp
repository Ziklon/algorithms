#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long  ll;
string line;
ll A,B,x,y;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(getline(cin,line)){
        istringstream is(line);
        is>>A;
        if(is>>B){
           int ans=0;
           if(A>B)swap(A,B);
           for(int i=A;i<=B;i++)if((i&1)==0 && i%4!=0)ans++;
           printf("%d\n",ans);     
        }else{
            if((A&1)==1 || A%4==0){                
                if(A%4==0){
                   x=(A/4)+1;
                   y=x-2;
                   if(A==0)y=x;
                }else{
                   x=((A+1LL)/2);
                   y=x-1;                  
                }
                printf("%lld %lld\n",x,y);
            }else{
               printf("Bachelor Number.\n");
            }
        }
   }
   return 0;      
}

