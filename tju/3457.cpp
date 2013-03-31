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
using namespace std;
int dp[26][26];
int T[26][26];

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int C;
	scanf("%d",&C);
	REP(i,0,C)
		REP(j,0,i+1)
			scanf("%d",&T[i][j]);
	
	
	//dp
	dp[0][0]=T[0][0];
	REP(i,1,C)
		REP(j,0,i+1){
			dp[i][j]=dp[i-1][j]+T[i][j];
			if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+T[i][j]);
		}
	int peki=0;
	REP(i,0,C)peki=max(peki,dp[C-1][i]);
	
	cout<<peki<<endl;
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
