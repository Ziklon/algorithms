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
int x,y,n,ans;
long long r,a,b;
void solve(){
	scanf("%d",&n);
	REP(t,0,n){
		scanf("%d %d",&x,&y);
		r=y-x;
		if(r<=2)ans=r;
		else{
			r-=2;
			a=2;
			ans=2;
			int i=2;
			while(r>0){
				r-=i;
				ans++;
				if(r>0){
					r-=i;
					ans++;
				}
				i++;
			}
		}
		printf("%d\n",ans);
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

