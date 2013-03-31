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
int n,A[1005],k;
int dp[1002][55];
int go(int p, int k){
   if(k<5 || n<=p)return k;
   int& ref=dp[p][k];
   if(ref!=-1)return ref;
   ref=go(p+1,k);
   ref=min(ref,go(p+1,k-A[p]));
   return ref;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1&&n){   
      REP(i,0,n)
         scanf("%d",&A[i]);
      scanf("%d",&k);
      sort(A,A+n);
      int j=0;
      REP(i,0,n){
         if(k<=50)break;
         k-=A[j++];
      }
      for(int i=n-1;i>=j && k>=5;i--)
         k-=A[i];
      printf("%d\n",k);
    }  
    //system("pause");
    return 0;
}
