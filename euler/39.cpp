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
   int ans=0;
   int num=0;
   
   for(int m=120;m<=1000;m++){
       int cnt=0;
       for(int i=1;i<=m;i++)
        for(int j=i+1;j+i<m;j++){
            int k=m-i-j;
            int A[]={i,j,k};
            sort(A,A+3);            
            if((A[0]+A[1])>A[2] && (A[1]-A[0])<A[2]){
               int c=A[2];
               int a=A[0];
               int b=A[1];
               if(c*c==(a*a)+(b*b)){
                 cnt++;
                 break;
               }                    
               //if(m==120)cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<endl; 
                    //cnt++;
                    //break;
            }
       }
       if(m==120){
          cout<<m<<" "<<cnt<<endl;
       }
       if(cnt>num){
          ans=m;
          num=cnt;
       }
   }
   cout<<ans<<" "<<num<<endl;
   return 0;      
}

