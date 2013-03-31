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
int F(int n){
	int ans=0;
	while(n){
		ans=(ans*10)+n%10;
		n/=10;
	}
	return ans;
}
void solve(){
	int n,a,b,r;
	scanf("%d\n",&n);
	REP(i,0,n){
		scanf("%d %d\n",&a,&b);
		r=F(F(a)+F(b));
		printf("Caso #%d: %d\n",i+1,r);
		
	}
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		freopen("D:/output.txt","w",stdout);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

