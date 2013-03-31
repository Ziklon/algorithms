/*
ID: winftc2
PROG: numtri
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int A[1000][1000],R,ans;
int dp[2][1001];
int main(){
	//clock_t start = clock();
    freopen("in.txt","r",stdin);
	//freopen("numtri.out","w",stdout);
	scanf("%d",&R);
	REP(i,0,R){
		for(int j=0;j<=i;j++)
			scanf("%d",&A[i][j]);
	}
	dp[0][0]=A[0][0];
	REP(i,1,R){
		int k=i&1;
		
		for(int j=0;j<=i;j++){
			dp[k][j]=dp[!k][j]+A[i][j];
			if(j>0)
				dp[k][j]=max(dp[!k][j-1]+A[i][j],dp[k][j]);
		}
	}
	ans=0;
	REP(i,0,R)ans=max(ans,dp[!(R&1)][i]);
	printf("%d\n",ans);
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
    return 0;
}
