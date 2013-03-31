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
#define INF 1<<30
using namespace std;
typedef long long ll;
ll dp[10005][110],T,m,n;
char z[10005],x[110];

ll go(int fir, int sec){
	if(sec>=n)return 1LL;
	if(fir>=m)return 0LL;
	ll& ref=dp[fir][sec];
	if(ref!=-1)return ref;
	ref=0;
	ref+=go(fir+1,sec);
	if(x[sec]==z[fir])ref+=go(fir+1,sec+1);		
	return ref;
}
void solve(){
	scanf("%d",&T);
	REP(t,0,T){
		scanf("%s\n",z);
		scanf("%s\n",x);
		fill(dp,-1);
		m=strlen(z);
		n=strlen(x);
		cout<<go(0,0)<<endl;		
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

