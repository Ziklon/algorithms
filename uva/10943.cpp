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
#define MOD 1000000
using namespace std;
int N,K;
int dp[102][102];


int go(int n, int k){
	if(k==0)return n==0;
	if(n<0 || k<0)return 0;
	int& ref=dp[n][k];
	if(ref!=-1)return ref;
	ref=0;
	for(int i=0;i<=n;i++)
		ref=(ref+go(n-i,k-1)%MOD)%MOD;
	return ref;
}




void solve(){
	fill(dp,-1);
	while(scanf("%d %d",&N,&K)==2 && N && K){
		printf("%d\n",go(N,K));
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


