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
int dp[700];

int go(int x){
   
   if(x==0)return 1;
   int& ref=dp[x];
   if(ref!=-1)return ref;
   ref=0;
   REP(i,1,x+1)
     ref+=go(x-i);  
   return ref; 
}


int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N;
    while(scanf("%d\n",&N)==1 && N){
        fill(dp,-1);
        cout<<go(N)<<endl;
         
    }
    //system("pause");
    return 0;
}
