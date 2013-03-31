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
int Z,N;
long long int i,j;
void solve(){
	scanf("%d",&Z);
	REP(t,0,Z){
		scanf("%d",&N);
		vector<long long> ans;		
		for(i=2;i*i<=N;i++){
			if(ans.sz>3)break;
			if(N%i==0){
				j=N/i;
				if(i!=j){
					ans.push_back(i);
					ans.push_back(j);
				}
			}	
		}
		printf("Case #%d: %d = %lld * %lld = %lld * %lld\n",t+1,N,ans[0],ans[1],ans[2],ans[3]);
	
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

