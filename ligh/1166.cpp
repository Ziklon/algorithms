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
int T,N,A[111],ans;
void solve(){
	scanf("%d",&T);
	REP(t,0,T){
		scanf("%d",&N);
		N++;
		REP(i,1,N)scanf("%d",&A[i]);
		
		ans=0;
		REP(i,1,N)if(i!=A[i]){
			REP(j,i+1,N)if(A[j]==i){
				ans++;
				swap(A[i],A[j]);				
			}
		}		
		printf("Case %d: %d\n",(t+1),ans);		
	
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

