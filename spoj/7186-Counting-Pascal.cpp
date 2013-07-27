#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define MAXN 2000
const int LIM=1000000000;
ll N;
ll ans;
int dp[MAXN][MAXN];

int main(){
	//freopen("input.txt","r",stdin);
	
	for(int i=0;i<MAXN;i++){
		dp[i][0]=dp[i][i]=((i+6LL)*(i+5LL)*(i+4LL))/6;		
	}
	//cout<<dp[1999][0]<<endl;
	
	for(int i=2;i<MAXN;i++)
		for(int j=1;j<i;j++){
			if(dp[i-1][j-1]==-1 || dp[i-1][j]==-1)dp[i][j]=-1;
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			if(dp[i][j]>LIM)
				dp[i][j]=-1;			
		}
	
	vector<int> v;
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<=i;j++)
				if(dp[i][j]>0)v.push_back(dp[i][j]);
	
	sort(v.begin(),v.end());
	
	while(scanf("%lld",&N)==1){
		if(N==-1)break;
		ans=N-1+N-2;
		int low=1;
		int hih=100000;
		while(low+1<hih){
			int mid=(low+hih)/2;
			ll tmp=(1LL*mid*(mid-1LL))/2;
			if(tmp>N)
				hih=mid-1;
			else
				low=mid;
		}
		if(N>=6){
			ans++;			
			if((hih*(hih-1))>2*N)hih--;
			
			ans+=((hih-4)*2);
		}
		ans+=upper_bound(v.begin(),v.end(),N)-v.begin();				
		printf("%lld\n",ans);
		
	}
	return 0;
}


