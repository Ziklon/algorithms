/*
ID: winftc2
PROG: holstein
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

void solve(){
	int N,T,lim;
	vector<int>v;
	scanf("%d",&N);
	v.resize(N);
	REP(i,0,N)scanf("%d",&v[i]);
	scanf("%d",&T);
	vector<vector<int> >w(T);
	REP(i,0,T){
		w[i].resize(N);
		REP(j,0,N)scanf("%d",&w[i][j]);
	}
	lim=1<<T;
	int Num=T,res=lim-1;
	
	for(int mask=0;mask<lim;mask++){
		vector<int> c(N,0);
		REP(i,0,T)
			if(mask&(1<<i))
				REP(j,0,N)
					c[j]+=w[i][j];
		bool ok=1;
		REP(i,0,N)
			if(c[i]<v[i])
				ok=0;
		
		if(ok &&__builtin_popcount(mask)<Num){
			Num=__builtin_popcount(mask);
			res=mask;
		}	
	}
	
	printf("%d",Num);
	REP(i,0,T)if(res&(1<<i))printf(" %d",i+1);
	printf("\n");
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	//freopen("holstein.in","r",stdin);
	//freopen("holstein.out","w",stdout);
	
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

