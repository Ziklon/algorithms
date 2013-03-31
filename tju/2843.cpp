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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define MOD 1000000007
using namespace std;
int dp[10000][3],N,K,peki;
int A[10000][3];
int go(int p, int u){
	if(p>=N)return 0;
	int& ref=dp[p][u];
	if(ref!=-1)return ref;
	ref=0;
	REP(i,0,3){
		if(u!=i)
			ref=max(ref,go(p+1,i)+A[p][i]);
	}
	return ref;
}
int main(){
    //freopen("in.txt","r",stdin);
	scanf("%d",&K);
	REP(k,0,K){
		scanf("%d",&N);
		REP(i,0,N){
			REP(j,0,3)
				scanf("%d",&A[i][j]);
		}
		peki=0;
		fill(dp,-1);
		REP(i,0,3)peki=max(peki,go(0,i));
		printf("%d\n",peki);
	}
	return 0;
}