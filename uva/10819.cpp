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
int dp[10201][103];
int m,n,A[102],B[102],ans;


int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   while(scanf("%d %d\n",&m,&n)==2){
        REP(i,0,n)
            scanf("%d %d",&A[i],&B[i]);
        if(m>2000)m=m+200;
        fill(dp,0);
        
        ans=0;
        REP(w,1,m+1)
            REP(i,1,n+1){
                dp[w][i]=dp[w][i-1];
                if(w>=A[i-1])
                    dp[w][i]=max(dp[w][i],B[i-1]+dp[w-A[i]][i-1]);
            }
        
        REP(i,0,n+1)ans=max(dp[m][i],ans);
        printf("%d\n",dp[m][n]);        
    }
   //system("pause");
   return 0;
}
