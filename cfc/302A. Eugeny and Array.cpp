#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 200005
int N,M,a,b,x,y;

int main(){
   scanf("%d %d",&N,&M);
   a=b=0;
   REP(i,N){
        scanf("%d",&x);
        if(x==1)a++;
        else b++;
   }      
   REP(i,M){
        scanf("%d %d",&x,&y);
        int dif=((y-x)+1)/2;        
        if(min(a,b)>=dif &&(y-x+1)%2==0 )puts("1");
        else puts("0");
   }   
   return 0;      
}
