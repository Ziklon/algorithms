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
int dp[30][30][400],L,S,ans,n;
int go(int p, int len, int sum){
	if(sum>S)return 0;
	if(len==L)return sum==S;
	int &ref=dp[p][len][sum];
	if(ref!=-1)return ref;
	ref=0;
	REP(i,p+1,26)ref+=go(i,len+1,sum+i+1);
	return ref;

}


void solve(){
	n=1;
	while(scanf("%d %d",&L,&S)==2 && !(S==0 && L==0)){
		ans=0;
		fill(dp,-1);
		if(L<=26)
			REP(i,0,26)ans+=go(i,1,i+1);
		
		printf("Case %d: %d\n",n++,ans);
	
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

