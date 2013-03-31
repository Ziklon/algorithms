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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;

int N;
ll dp[50][3],ans;	
void solve(){
	scanf("%d",&N);
	dp[1][0]=1;
	dp[1][1]=0;
	dp[1][2]=1;
	
	for(int i=2;i<=N;i++){
		dp[i][0]=dp[i-1][1]+dp[i-1][2];
		dp[i][2]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];		
	}
	ans=dp[N][0]+dp[N][2];
	printf("%lld\n",ans);
	
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

