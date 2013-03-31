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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int M,T,coins[105],ans,sum,med;
bool dp[25005];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        scanf("%d\n",&M);
        sum=0;
        for(int j=0;j<M;j++){
          scanf("%d",&coins[j]);
          sum+=coins[j];
        }
        med=sum/2;
        fill(dp,0);
        dp[0]=1;
        for(int j=0;j<M;j++){          
          for(int k=med;k>=1;k--){
            if(!dp[k])
              if(coins[j]<=k)
                dp[k]=dp[k-coins[j]];
          }
        }
        int ps;
        for(ps=med;ps>=1;ps--)
          if(dp[ps])break;
                
        cout << abs(sum - ps * 2)<<endl;
    }
    //system("pause");
    return 0;
}
