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
#define x first
#define y second
using namespace std;
typedef long long ll;
int S;
ll dp[12][85],ans;
void solve(){
	scanf("%d",&S);
	
	for(int i=0;i<=81;i++)
		for(int j=0;j<12;j++)
			dp[j][i]=0;
	
	dp[0][0]=1;
	for(int c=1;c<=10;c++){	
		for(int s=1;s<=S;s++){			
			for(int d=0;d<10;d++){
				if(s>=d)
					dp[c][s]+=dp[c-1][s-d];			
			}	
		}			
	}
	ans=0;
	if(S==1)ans++;
	
	for(int c=1;c<=9;c++)ans+=dp[c][S];
	
	cout<<ans<<endl;
		
	
	
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

