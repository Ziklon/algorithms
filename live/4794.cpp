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
int r,m,n,s;
void solve(){
	int T=1;
	while(scanf("%d",&r)==1 && r){
		scanf("%d %d",&m,&n);
		vector<int> v(r);
		s=0;
		bool ok=1;
		REP(i,0,r){
			scanf("%d",&v[i]);
			s+=v[i];
			if(v[i]>max(m,n))
				ok=0;
		}
		sort(rall(v));
		printf("Case %d: ",T++);
		if(s!=(m*n) || ok==0){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
	
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

