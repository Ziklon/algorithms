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
#define MAX 100005
using namespace std;
int A[MAX],N,ans,lo,hi,S;
void solve(){
	while(scanf("%d",&N)==1){
		S=0;
		REP(i,0,N)scanf("%d",&A[i]),S+=A[i];		
		if(S%N)puts("-1");
		else{
			S=S/N;
			int x=0;
			int y=N-1;
			ans=0;
			while(x<y){
				int m=min(S-A[x],A[y]-S);
				A[x]+=m;
				A[y]-=m;
				ans+=m;
				if(A[x]==S)x++;
				if(A[y]==S)y--;				
			}
			bool ok=1;
			REP(i,0,N)if(A[i]!=S)ok=0;			
			if(ok)printf("%d\n",ans+1);
			else puts("-1");
			
		}
				
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

