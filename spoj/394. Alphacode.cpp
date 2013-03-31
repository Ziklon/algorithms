#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
string text;
ll dp[50000];
int N;

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(getline(cin,text)){
        if(text=="0")break;
        N=text.size();
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=0;i<N;i++){
            if(text[i]>='1' && text[i]<='9')dp[i+1]+=dp[i];
            if(i+1<N){
               int val=((text[i]-'0')*10)+(text[i+1]-'0');
               if(val>=10 && val<=26)
                  dp[i+2]+=dp[i];
            }
        }
        printf("%lld\n",dp[N]);
   }   
   return 0;      
}
