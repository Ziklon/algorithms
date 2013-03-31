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

double dp[1<<20],D[20][20];
int N,X[20],Y[20],L=1<<20,M=1;
char buff[120];
double go(int mask){	
	if(__builtin_popcount(mask)==N*2)return 0;
	double &ref=dp[mask];
	if(ref>=0)return ref;
	ref=oo;
	REP(i,0,N*2){
		if(!(mask&(1<<i))){
			REP(j,i+1,N*2)if(!(mask&(1<<j))){				
				int num=mask|(1<<i);
				num=num|(1<<j);
				ref=min(ref,go(num)+D[i][j]);
			}		
		}
	}
	return ref;


}

void solve(){
	while(scanf("%d\n",&N)==1 && N){
		REP(i,0,2*N){
			scanf("%s %d %d\n",buff,&X[i],&Y[i]);
			//cout<<buff<<endl;
		}
		REP(i,0,N*2)
			REP(j,i+1,N*2)
				D[i][j]=hypot(X[i]-X[j],Y[i]-Y[j]);
				
		REP(i,0,L)dp[i]=-1.0;
		double ans=go(0);
		
		printf("Case %d: %0.2f\n",M++,ans);
		
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

