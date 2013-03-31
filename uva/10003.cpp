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
int N,L,A[55],T;
int dp[55][55];

int go(int p, int q){
	
	if(q-p<=1)return 0;
	int& ref=dp[p][q];
	if(ref!=-1)return ref;
	ref=oo;
	REP(i,p+1,q){
		ref=min(ref,A[q]-A[p]+(go(p,i)+go(i,q)));	
	}	
	return ref;
}
void solve(){
	while(scanf("%d",&N)==1 && N){
		scanf("%d",&T);
		A[0]=0;
		REP(i,0,T)scanf("%d",&A[i+1]);
		A[T+1]=N;
		fill(dp,-1);
		
		
		printf("The minimum cutting is %d.\n",go(0,T+1));	
		
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

