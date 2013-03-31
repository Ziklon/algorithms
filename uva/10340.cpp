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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
int dp[1010][1010];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b;
    //10340
    while(cin>>a>>b){
       fill(dp,0);
       for(int i=1;i<=a.sz;i++)
         for(int j=1;j<=b.sz;j++){
            if(a[i-1]==b[j-1])
               dp[i][j]=dp[i-1][j-1]+1;
            else
               dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
         }
      if(dp[a.sz][b.sz]==a.sz)printf("Yes\n");
      else printf("No\n");
    }
    return 0;
}
