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
int A[101][101];
int S[101][101];
int N,K;
ll ans;
void solve(){
	scanf("%d",&N);
	ans=-127000000000LL;
	REP(i,0,N)REP(j,0,N)scanf("%d",&A[i][j]);
	
	REP(i,0,N){
		int rowSum=0;
		REP(j,0,N){
			S[i][j]=A[i][j];
			if(i>0)S[i][j]+=S[i-1][j];
			S[i][j]+=rowSum;
			rowSum+=A[i][j];
		}
	}
	for(int r=0;r<N;r++)
		for(int c=0;c<N;c++)
			for(int h=r;h<N;h++)
				for(int w=c;w<N;w++){
					ans=max(ans,0LL+S[h][w]-S[r-1][w]+S[r-1][c-1]-S[h-1][c-1]);
				}

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

