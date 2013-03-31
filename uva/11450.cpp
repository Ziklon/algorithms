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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int T,M,C,K,res,ii,i,j,k;
int A[20][22];
int dp[2][201];

void solve(){
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		scanf("%d %d",&M,&C);		
		for(int c=0;c<C;c++){			
			scanf("%d",&K);
			A[c][0]=K;
			for(int k=1;k<=K;k++)
				scanf("%d",&A[c][k]);			
		}
		//fill(dp,0);
		dp[0][0]=1;
		for(i=1;i<=C;i++){
			ii=i&1;			
			for(j=200;j>=0;j--){
				dp[ii][j]=0;
				for(k=1;k<=(A[i-1][0]);k++){
					if(j>=A[i-1][k])
						dp[ii][j]|=dp[1-ii][j-A[i-1][k]];
				}			
			}		
		}
		res=-1;
		ii=C&1;	
		for(int i=1;i<=M;i++)if(dp[ii][i])res=i;
		if(res<0)printf("no solution\n");
		else printf("%d\n",res);		
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

