#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#define all(v) (v).begin(),(v).end()
#define sz size()

using namespace std;

int dp[1050];

int go(int val){
   if(val<0)return 1<<29;
   if(val==0)return 0;
   int& ref=dp[val];
   if(ref==-1){
      ref=1<<29;
      for(int i=1;i<=6;i++)
         ref=min(ref,1+go(val-(i*i)));
   }
   return ref;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long sum,ans,i;
    int nn;
    for(int i=0;i<1050;i++)dp[i]=-1;
    
    while(1){
       sum=0;  
       for(i=1;i<=6;i++){
         scanf("%d",&nn);
         sum+=((i*i)*nn);
       }
       ans=0;
       if(!sum)break;
       if(sum>1000){
         ans=(sum-1000)/36;
         nn=(sum-1000)%36;
         sum=1000+nn;
       }
       //cout<<ans<<endl;
       ans+=go(sum);
       printf("%lld\n",ans);      
       
    }
    
    return 0;
}
