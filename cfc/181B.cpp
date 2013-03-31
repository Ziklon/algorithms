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
vector<pair<int,int> >v;
pair<int,int> p;
void solve(){
	int n,a,b;
	scanf("%d",&n);
	REP(i,0,n){
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	sort(all(v));
	int ans=0;
	REP(i,0,n)REP(j,i+1,n){
		a=(v[j].first+v[i].first);
		b=(v[j].second+v[i].second);
		if((a&1) || (b&1) )continue;
		a/=2;
		b/=2;
		p=make_pair(a,b);		
		if(binary_search(all(v),p))ans++;
	
	}
	printf("%d\n",ans);
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

