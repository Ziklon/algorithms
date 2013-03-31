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

int N,A[30],B[30],ans;

void solve(){
	while(scanf("%d",&N)==1){
		REP(i,0,N)scanf("%d",&A[i]);
		REP(i,0,N)scanf("%d",&B[i]);
		map<int,int>Ma,Mb;
		REP(i,0,N)Ma[A[i]]=i;		
		REP(i,0,N)Mb[B[i]]=i;
		ans=0;
		REP(i,0,N){
			int x=i+1;
			vector<int> a,b;
			REP(j,Ma[x]+1,N)a.push_back(A[j]);			
			REP(j,Mb[x]+1,N)b.push_back(B[j]);
			sort(all(a));
			sort(all(b));
			REP(j,0,b.sz)
				if(!binary_search(all(a),b[j]))
					ans++;			
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

