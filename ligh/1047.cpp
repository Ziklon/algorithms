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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define oo 1<<30
using namespace std;
int T,A[21][3],N;
int dp[21][4];

void solve(){
	scanf("%d",&T);
	REP(t,0,T){
		scanf("%d",&N);
		REP(i,0,N)
			REP(j,0,3)scanf("%d",&A[i][j]);		
		for(int i=N-1;i>=0;i--){			
			for(int j=0;j<3;j++){				
				dp[i][j]=A[i][j];
				if(i!=N-1)dp[i][j]+=min(dp[i+1][(j+1)%3],dp[i+1][(3+j-1)%3]);				
			}		
		}
		int ans=min(dp[0][1],min(dp[0][0],dp[0][2]));
		printf("Case %d: %d\n",t+1,ans);	
	}
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

