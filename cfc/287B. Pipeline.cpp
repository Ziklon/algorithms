#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

ll N,K,A,B,X,Y;


int main(){
   cin>>N>>K;
   A=(K*(K+1))/2-(K-1);
   if(N==1){
       puts("0");
       return 0;
   }
   if(N>A){
        puts("-1");
        return 0;
   }
   ll low=1;
   ll hih=K;
   ll ans;
   while(hih-low>1){
        ll mid=(low+hih)>>1;
        Y=(K*(K+1))>>1;
        X=(mid*(mid+1LL))>>1;
        Y=Y-X-(K-mid-1);
        if(Y<N)
            hih=mid;
        else 
            low=mid;
   }
   ans=K-hih+1;
   cout<<ans<<endl;   
   return 0;      
}
