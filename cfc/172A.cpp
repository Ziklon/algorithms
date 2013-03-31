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
char A[40000][25];
void solve(){
	int n,tam;
	scanf("%d\n",&n);
	REP(i,0,n)
		scanf("%s\n",A[i]);
	int ans=0;
	tam=strlen(A[0]);
	//char cur;
	REP(i,0,tam){
		int dif=0;
		
		REP(j,0,n){
			dif+=A[0][i]!=A[j][i];
		}
		if(dif>0)break;
		ans+=1;
	}
	printf("%d\n",ans);
		
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

