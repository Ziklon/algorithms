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
int T,D,N,A[50005],B[50005],C[1000005],S;
bool V[1000000];
void solve(){
	scanf("%d",&T);
	REP(i,0,T){
		scanf("%d %d",&D,&N);
		B[0]=0;
		fill(C,0);
		REP(i,0,N){
			scanf("%d",&A[i]);
			B[i+1]=((A[i]%D)+B[i])%D;
		}
		S=0;
		REP(i,0,N){
			S=(S+B[i])%D;
			C[S]++;		
		}
		S=0;
		REP(i,1,D)S+=C[i];
		printf("%d\n",S);
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

