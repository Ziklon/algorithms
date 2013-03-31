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
int L,n,k,A,B;
void solve(){
	scanf("%d\n",&n);
	REP(i,0,n){
		scanf("%d %d",&L,&k);
		vector<int> v(k);
		REP(j,0,k)scanf("%d",&v[j]);
		sort(all(v));
		A=0;
		B=0;
		REP(j,0,k){
			A=max(A,min(v[j],L-v[j]));
			B=max(B,max(v[j],L-v[j]));
		}		
		printf("%d %d\n",A,B);			
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

