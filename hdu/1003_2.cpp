#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
#define MIN -1010
#define LIM 100010
int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T,ans,A[LIM],n,dp[2],B[LIM],pt,x,y;
   scanf("%d",&T);
   for(int i=1;i<=T;i++){
      scanf("%d",&n);
      
      for(int j=0;j<n;j++)
         scanf("%d",&A[j]);
      
      dp[0]=A[0];
      fill(B,-1);
      for(int j=1;j<n;j++){
         if(A[j]>dp[j-1]+A[j]){
            dp[j]=A[j];
            B[j]=-1;
         }else{
            dp[j]=A[j]+dp[j-1];
            B[j]=j-1;
         }
      }
      ans=MIN;
      for(int j=0;j<n;j++)if(ans<dp[j]){
         ans=dp[j];
         pt=j;
      }
      y=pt;
      x=pt;
      while(1){
         if(B[x]==-1)break;
         x=B[x];
      }
      printf("Case %d:\n",i);
      printf("%d %d %d\n",ans,x+1,y+1); 
      if(i<T)printf("\n"); 
   }
   return 0;
}
