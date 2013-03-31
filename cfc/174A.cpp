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
#define EPS 1e-9
using namespace std;
int n,b;

void solve(){
	scanf("%d %d",&n,&b);
	vector<int>v(n);
	vector<double> ans(n);
	int sum=0;
	double res=0;
	bool ok=1;
	REP(i,0,n){
		scanf("%d",&v[i]);
		sum+=v[i];
	}
	res=b;
	REP(i,0,n){
		ans[i]=max(((sum+b+0.0)/n)-v[i],0.0);
		res-=ans[i];
	}
	//cout<<res<<endl;
	if(abs(res)>(EPS))ok=0;
	if(ok)REP(i,0,n)printf("%.6f\n",ans[i]);
	else printf("%d\n",-1);	
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

