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
int A[150],B[150];
void solve(){
	int n,m;
	cin>>n>>m;
	REP(i,0,n+1)scanf("%d",&A[i]);
	REP(i,0,n+1)scanf("%d",&B[i]);
	int g=__gcd(A[0],B[0]);
	
	if(A[0]==B[0]){
		puts("0/1");
	}else if(A[0]>B[0]){
		A[0]/=g;
		B[0]/=g;
		A[0]=abs(A[0]);
		
		B[0]=abs(B[0]);

		if(B[0]==1)printf("%d",A[0]);
		else printf("%d/%d",A[0],B[0]);		 
	}else{
		if(A[0]<)
	
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

