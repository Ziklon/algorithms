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


bool cmp(pair<int,int> p, pair<int,int>q){
	if(p.first!=q.first)
		return p.first>q.first;
	return p.second<q.second;

}
void solve(){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int> >v(n);
	REP(i,0,n){
		cin>>v[i].first>>v[i].second;
	}
	sort(all(v),cmp);
	int ans=0;
	for(int i=k;i<n && v[k-1]==v[i];i++)ans++;
	for(int i=k-1;i>=0 && v[k-1]==v[i];i--)ans++;
	
	cout<<ans<<endl;
	
	
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

