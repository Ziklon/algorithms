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
int types[5]={1,5,10,25,50};
long long dp[30005][5];

long long go(int c, int t){
   if(c<0 || t>4)return 0; 
   if(c==0)return 1;
   long long& ref=dp[c][t];
   if(ref!=-1)return ref;
   
   ref=0;
   ref+=go(c-types[t],t);
   ref+=go(c,t+1);
   return ref;  
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long ans=0;
    int num;
    fill(dp,-1);
    while(cin>>num){
         ans=go(num,0);
         if(ans==1) c 
            cout<<"There is only 1 way to produce "<<num<<" cents change."<<endl;
         else
            cout<<"There are "<<ans<<" ways to produce "<<num<<" cents change."<<endl;             
    }
    //system("pause");
    return 0;
}
