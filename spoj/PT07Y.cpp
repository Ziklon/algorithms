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
int A[10005];
int FIND(int p){
	if(A[p]==p)return p;
	return A[p]=FIND(A[p]);
}

void UNION(int p, int q){
	A[FIND(p)]=FIND(q);
}

void solve(){
	int N,M,p,q,r;
	scanf("%d %d",&N,&M);
	REP(i,0,N+2){
		A[i]=i;
	}
	bool ok=1;
	r=0;
	REP(i,0,M){
		scanf("%d %d",&p,&q);
		if(ok && FIND(p)==FIND(q)){
			ok=0;			
		}else{
			UNION(p,q);
		}		
	}
	
	REP(i,1,N+1)r+=A[i]==i;	
	ok=ok&&r==1;
	if(ok)puts("YES");
	else puts("NO");	
	
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

