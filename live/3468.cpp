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
int A[5005];
int dp[5005],ans;


int go(){
	dp[0]=1-A[0];
	dp[1]=min(1-A[1],dp[0]);
	
	REP(i,2,N){
		if(A[i]==1)
			dp[i]=dp[i-1];
		else{
			dp[i]=(1-A[i])+min(dp[i-2],dp[i-1]);
			if(A[i-1]==1)
				dp[i]=min(dp[i],dp[i-1]);		
		}
	}
	return dp[N-1];	
}

void solve(){
	while(scanf("%d",&N)==1 && N){
		REP(i,0,N)scanf("%d",&A[i]);
		ans=go();
		printf("%d\n",ans);
	}

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


