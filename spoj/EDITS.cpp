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
#define INF 1<<20
using namespace std;
typedef long long ll;
string a,b;
int n,m,t;
int dp[2005][2005],ans,val,tmp1,tmp2;

int main(){
	scanf("%d",&t);
	while(t--){
		cin>>a>>b;
		dp[0][0]=0;
		
		for(int i=1;i<=a.sz;i++)dp[i][0]=i;
		for(int j=1;j<=b.sz;j++)dp[0][j]=j;
		
		for(int i=1;i<=a.sz;i++){
			for(int j=1;j<=b.sz;j++){
				val=(a[i-1]==b[j-1])?0:1;
				tmp1=min(dp[i-1][j]+1,dp[i][j-1]+1);
				tmp2=dp[i-1][j-1]+val;
				dp[i][j]=min(tmp1,tmp2);
			}
		}
		ans=dp[a.sz][b.sz];
		printf("%d\n",ans);
	}	
}
