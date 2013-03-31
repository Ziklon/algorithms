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
int dp[2][1000];
string a,b;


void solve(){
	a="margarita";
	b="carlitos";
	for(int i=a.sz;i>=0;i--){
		int ii=i&1;
		for(int j=b.sz;j>=0;j--){
			if(i==a.sz || j==b.sz)dp[ii][j]=0;
			else if(a[i]==b[j])dp[ii][j]=1+dp[1-ii][j+1];
			else dp[ii][j]=max(dp[1-ii][j],dp[ii][j+1]);
		}
	}
	cout<<dp[0][0]<<endl;
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

