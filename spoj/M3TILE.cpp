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
typedef long long ll;
int n,m;
int main(){
	ll dp[2][31],ans;
	dp[0][0]=0;dp[1][0]=1;
	dp[0][1]=1;dp[1][1]=2;	
	
	for(int i=2;i<=15;i++){
		dp[0][i]=dp[0][i-1]+dp[1][i-1];
		dp[1][i]=(2*dp[0][i-1])+(dp[1][i-1]*3);
	}
	while(scanf("%d",&n)==1 &&  n>=0){
		ans=dp[0][n/2]+dp[1][n/2];
		if(n&1)cout<<0<<endl;
		else cout<<ans<<endl;	
		
	}	
	return 0;
}
