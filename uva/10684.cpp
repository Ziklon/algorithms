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
//10684
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n,A[10010],maxSum,thisSum;
   while(scanf("%d",&n)&& n){
      for(int i=0;i<n;i++)scanf("%d",&A[i]);
      maxSum=A[0];
      thisSum=A[0];
      for(int i=1;i<n;i++){
         if(thisSum+A[i]<A[i])
            thisSum=A[i];
         else
            thisSum+=A[i];
         maxSum=max(maxSum,thisSum);
      }
      if(maxSum>0)printf("The maximum winning streak is %d.\n",maxSum);
      else printf("Losing streak.\n");      
   }
   return 0;
}
