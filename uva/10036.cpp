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
int dp[10000][101][2],N,K,A[10005],C,res;

int go(int index,int res, int sig){
	if(index>=N)return res==0;
	int& ref=dp[index][res][sig];
	if(ref!=-1)return ref;
	ref=0;
	ref=max(ref,go(index+1,((10000*K)+res-A[index])%K,0));
	ref=max(ref,go(index+1,((10000*K)+res+A[index])%K,1));
	return ref;
}

void solve(){
	scanf("%d",&C);
	REP(i,0,C){
		scanf("%d %d",&N,&K);
		REP(i,0,N)scanf("%d",&A[i]);
		fill(dp,-1);
		res=max(go(0,0,0),go(0,0,1));
		puts(res?"Divisible":"Not divisible");
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

