#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
long int A,B,i,steps,val,tmp,ans;
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif    
   while(scanf("%ld %ld",&A,&B)==2){
        if(A==B && A==0)break;
        if(A>B)swap(A,B);
        steps=0;
        ans=0;
        for(i=A;i<=B;i++){
            tmp=0;
            val=i;
            do{
                tmp++;
                if(val&1)val=(3*val)+1;
                else val=val>>1;
            }while(val!=1);
            if(tmp>steps){
                steps=tmp;
                ans=i;
            }
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",A,B,ans,steps);
   }
   return 0;      
}
