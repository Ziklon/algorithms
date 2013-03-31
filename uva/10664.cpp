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
int dp[250];
int vals[25];

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int k,j,va,tot;
   string line;
   scanf("%d\n",&k);
   REP(i,0,k){
      getline(cin,line);
      istringstream is(line);
      j=0;
      tot=0;
      while(is>>va){
        vals[j++]=va;
        tot+=va;
      }
      fill(dp,0);
      dp[0]=1;
      REP(k,0,j){
        for(int s=tot/2;s>=vals[k];s--){
            if(dp[s-vals[k]])
                dp[s]=1;
        }
      }
      if(!(tot&1)&& dp[tot/2])
        printf("YES\n");
      else 
        printf("NO\n");           
      
   }
   //system("pause");
   return 0;
}
