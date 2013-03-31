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

long long dp[27][160],M,P,Q;
int T,N,X;

long long gcd(long long a, long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}

long long go(int n, int sum){
	if(n==0 && sum>=X)return 1LL;
	if(n<0)return 0;
	long long& ref=dp[n][sum];
	if(ref!=-1)return ref;
	ref=0;
	REP(i,1,7)
		ref+=go(n-1,min(X,sum+i));
	return ref;
}


void solve(){
	scanf("%d",&T);

	REP(i,0,T){
		scanf("%d %d",&N,&X);
		fill(dp,-1);
		Q=1;
		REP(j,0,N)Q*=6;
			
		P=go(N,0);
		M=gcd(Q,P);
		P/=M;
		Q/=M;
		if(Q!=1)cout<<"Case "<<(i+1)<<": "<<P<<"/"<<Q<<endl;
		else cout<<"Case "<<(i+1)<<": "<<P<<endl;
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

