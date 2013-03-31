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
int G[501][101];
int N,D,ans;
void solve(){
	while(scanf("%d %d",&N,&D)==2){
		
		if(N==0 && D==0)break;
		REP(i,0,D)REP(j,0,N)scanf("%d",&G[i][j]);
		
		ans=0;
				
		REP(j,0,N){
			int ok=1;
			REP(i,0,D)if(G[i][j]==0)ok=0;
			ans+=ok;
		}
		if(ans>0)puts("yes");
		else puts("no");
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

