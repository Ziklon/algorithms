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
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
#define MOD 1000000
using namespace std;
int dp[MOD+5],a,b,c,n;
void solve(){
	dp[0]=1;
	for(int i=1;i<=MOD;i++){
		a=i-sqrt(double(i));
		b=log(double(i));
		c=(sin(double(i))*sin(double(i)))*i;
		dp[i]=(dp[a]+dp[b]+dp[c])%MOD;
	}
	while(scanf("%d",&n)==1 && n>=0)
		printf("%d\n",dp[n]);
	
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

