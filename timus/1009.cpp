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

int N,K;
ll dp[30][12],ans;	
void solve(){
	scanf("%d",&N);
	scanf("%d",&K);
	dp[1][0]=0;
	for(int i=1;i<K;i++)dp[1][i]=1;
	
	
	for(int n=2;n<=N;n++){
		for(int k=0;k<K;k++){
			dp[n][k]=0;
			for(int m=0;m<K;m++)
				if(!(k==0 && m==0))
					dp[n][k]+=dp[n-1][m];
			
		}	
	}
	ans=0;
	for(int i=0;i<K;i++)ans+=dp[N][i];
	
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

