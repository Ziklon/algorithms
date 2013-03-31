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
long long N,MOD=1000000007,res;

long long fastExpo(long long n){
	if(n==0)return 1;
	long long ans=fastExpo(n>>1);
	ans=(ans*ans)%MOD;
	if((n&1)!=0)
		ans=(ans*2LL)%MOD;
	return ans;
}

void solve(){
	cin>>N;
	if(N!=0){
		res=fastExpo(N-1)*(fastExpo(N)+1);	
		res=res%MOD;
	}else{
		res=1;
	}
	cout<<res<<endl;
	
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

