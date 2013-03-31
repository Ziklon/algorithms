#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 100005
int N,S=0,tmp;
int ans=0;
int main(){
   scanf("%d",&N);
   REP(i,N){
       scanf("%d",&tmp);
       S+=tmp;
   }
   if(S%N==0)printf("%d\n",N);
   else printf("%d\n",N-1);
   
   return 0;      
}
