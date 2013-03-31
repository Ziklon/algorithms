/*
ID: winftc2
PROG: sort3
LANG: C++
*/
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
int A[2000],N,B[2000];
int ans;

void solve(){
	scanf("%d",&N);
	REP(i,0,N){
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
	sort(B,B+N);
	int ans=0;
	REP(i,0,N)ans+=B[i]!=A[i];
	ans=(ans+1)/2;
	printf("%d\n",ans);
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	//freopen("sort3.in","r",stdin);
	//freopen("sort3.out","w",stdout);
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

