#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int T,N;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   scanf("%d",&T);
   while(T--){
       scanf("%d",&N);
       if(N==1)printf("1\n");
       else{
           vector<int> v; 
           for(int i=9;i>=2;i--)while(N%i==0){
                v.push_back(i);
                N/=i;
           }
           sort(v.begin(),v.end());
           if(N!=1)printf("-1\n");
           else{
              REP(i,v.size())printf("%d",v[i]);
              printf("\n");  
           } 
       } 
   }
   return 0;      
}

