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
int A[100005],dp[100005],N,M,X,Y,B[100005];
int go(int row){
	if(row>=N)return 0;
	int& ref=dp[row];
	if(ref!=-1)return ref;
	ref=0;
	ref=max(ref,go(row+1));
	ref=max(ref,go(row+2)+A[row]);
	return ref;	
}

void solve(){
	while(scanf("%d %d",&M,&N)==2 && (M!=0 && N!=0)){
		REP(i,0,M){
			REP(j,0,N)scanf("%d",&A[j]);
			fill(dp,-1);
			B[i]=go(0);
			//printf("%d ",B[i]);
		}
		REP(i,0,M)A[i]=B[i];
		fill(dp,-1);
		//printf("\n");
		N=M;
		printf("%d\n",go(0));	
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

