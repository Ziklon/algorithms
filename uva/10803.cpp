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
int N,n;
double dp[101][101],ans;
double D[101][101];
pair<int,int> G[101];
void solve(){
	scanf("%d",&N);
	REP(t,0,N){
		scanf("%d",&n);
		REP(j,0,n){
			scanf("%d %d",&G[j].first,&G[j].second);
		}
		REP(i,0,n)REP(j,0,n){
			if(i==j){
				dp[i][j]=0;
			}
			else {
				dp[i][j]=hypot(G[i].first-G[j].first,G[i].second-G[j].second);
				if(dp[i][j]>10.)
					dp[i][j]=1e+20;
			}
		}
		ans=0;
		
		REP(k,0,n)REP(i,0,n)REP(j,0,n){
			dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);			
		}
		REP(i,0,n)REP(j,0,n)ans=max(ans,dp[i][j]);
		printf("Case #%d:\n",t+1);
		if(ans>=1e+20)printf("Send Kurdy\n");
		else printf("%0.4f\n",ans);
		printf("\n");
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

