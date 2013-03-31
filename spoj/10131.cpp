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
pair<int,int>A[1010];
int x,y,dp[101];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n=0,ans=0;
    while(scanf("%d %d",&x,&y)==2){
      A[n].first=x;
      A[n].second=y;
      n++;
    }
    for(int i=0;i<n;i++){
      dp[i]=1;
      for(int j=0;j<i;j++)
         if(A[j].first>A[i].first && A[j].seond<A[i].second)
            dp[i]=max(dp[i],dp[j]+1);
    }
    for(int i=0;i<n;i++)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
