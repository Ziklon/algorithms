#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
ll N,K,fi,ti;

int main(){
   #ifdef LocalHost
        freopen("D:/input.txt","r",stdin);
   #endif
   cin>>N>>K;
   ll ans=-1LL<<40;
   REP(i,N){
        cin>>fi>>ti;
        if(ti>=K)
        ans=max(ans,fi-(ti-K));
        else ans=max(ans,fi);
        
   }
   cout<<ans<<endl;          
   return 0;      
}
