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
long long N,ans;
void solve(){
	cin>>N;
	ans=1LL<<60;
	REP(i,0,11){
		REP(mask,0,1<<i){
			if(__builtin_popcount(mask)*2==i){			
				long long aux=0;
				REP(j,0,i)if(mask&(1<<j))aux=(aux*10)+4;
						  else aux=aux*10+7;
				if(aux>=N)ans=min(ans,aux);
			}
		
		}
		
	}
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

