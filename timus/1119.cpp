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
#define INF 1e+10
using namespace std;
typedef long long ll;

int N,M,x,y,K;
ll ans;
double dp[2][1004];
bool D[1005][1001];
double cross=sqrt(20000.);
void solve(){

	scanf("%d %d",&N,&M);
	
		scanf("%d",&K);
		fill(D,0);
		REP(i,0,K){
			scanf("%d %d",&x,&y);
			D[x-1][y-1]=1;
		}
		for(int i=0;i<2;i++)for(int j=1;j<=M;j++)dp[i][j]=INF;
		dp[0][0]=0;
		for(int i=0;i<=N;i++){
			int ii=i&1;
			for(int j=0;j<=M;j++)dp[1-ii][j]=INF;
			for(int j=0;j<=M;j++){
				dp[ii][j+1]=min(dp[ii][j+1],dp[ii][j]+100.0);
				dp[1-ii][j]=min(dp[1-ii][j],dp[ii][j]+100.0);	
				if(D[i][j]==1)
					dp[1-ii][j+1]=min(dp[1-ii][j+1],dp[ii][j]+cross);
			}		
		}
		ans=(int)(dp[(N&1)][M]+.5);
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

