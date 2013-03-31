/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int N,K;
long long dp[2<<16][16];
vector<int>v;
long long go(int mask, int index){
   if(__builtin_popcount(mask)==N)return 1;
   long long& ref=dp[mask][index];
   if(ref!=-1)return ref;
   ref=0;
   REP(i,0,N){
      if((mask&(1<<i))==0 && abs(v[i]-v[index])>K){
         ref+=go(mask+(1<<i),i);
      }
   }
   return ref;   
}   
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>N>>K;
    v.resize(N);
    REP(i,0,N)
      cin>>v[i];
    fill(dp,-1);
    long long ans=0;
    REP(i,0,N){
      ans+=go(1<<i,i);
    }
    cout<<ans<<endl;  
    //system("pause");
    return 0;
}
