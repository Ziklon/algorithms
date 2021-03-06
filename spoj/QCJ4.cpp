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

int A[301],B[301],x,y,n;

void solve(){
	scanf("%d",&n);
	set<int> sA,sB;
	double aa=0;
	double bb=0;
	REP(i,0,n){
		scanf("%d %d",&x,&y);
		A[i]=x;
		B[i]=y;
		sA.insert(x);
		sB.insert(y);
	}
	foreach(sA,it)aa+=(*it);
	foreach(sB,it)bb+=(*it);
	aa=aa/sA.sz;
	bb=bb/sB.sz;
	double ans=0;
	REP(i,0,n){
		ans=max(ans,hypot(A[i]-aa,B[i]-bb));
	}
	ans*=2;
	printf("%.2f\n",ans);
	
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

