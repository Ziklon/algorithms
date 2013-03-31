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
int dp[1<<12],n,m;
char buff[32];

int go(int mask){	
	if(dp[mask]!=-1)return dp[mask];
	int ans=__builtin_popcount(mask);
	REP(i,0,10){
		int j=i+1;
		int k=i+2;
		int newMask=mask;
		newMask &= ~(1 << i);
		newMask &= ~(1 << j);
		newMask &= ~(1 << k);		
		if((mask&(1<<i))==0 && (mask&(1<<j)) && (mask&(1<<k)))			
			ans=min(ans,go(newMask|(1<<i)));				
		if((mask&(1<<i)) && (mask&(1<<j)) && (mask&(1<<k))==0)			
			ans=min(ans,go(newMask|(1<<k)));
		
	}
	dp[mask]=ans;
	return ans;
}

void solve(){
	scanf("%d\n",&n);
	REP(t,0,n){
		scanf("%s\n",buff);
		m=0;
		fill(dp,-1);
		REP(i,0,12){
			if(buff[i]=='o')
				m|=(1<<i);
		}
		cout<<go(m)<<endl;
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

