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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
ll n,mid;
ll S(ll x){
	ll ans=0;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
ll f(ll x){
	return ((x*x) + (S(x)*x)) ;
}
void solve(){
	cin>>n;
	mid=max(0,((int)sqrt(n))-2000000);
	vector<ll> v;
	for(ll x=mid,m=0;m<4000000;x++,m++){			
		if(f(x)==n)
			v.push_back(x);		
	}	
	sort(all(v));
	if(v.sz==0)cout<<-1<<endl;
	else cout<<v[0]<<endl;
	
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

