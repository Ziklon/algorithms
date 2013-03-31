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
int a,b,c,d,r;
int len(int a){
	int ans=1;
	while(a!=1){
		if(!(a&1))a=a>>1;
		else a=(a*3)+1;
		ans++;
	}
	return ans;

}

void solve(){
	while(scanf("%d %d",&a,&b)==2){
		c=min(a,b);
		d=max(a,b);
		r=0;
		for(int i=c;i<=d;i++){
			r=max(r,len(i));
		}
		printf("%d %d %d\n",a,b,r);
	
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

