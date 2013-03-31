#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll N,dp[90];
int main(){
	ios::sync_with_stdio(false);
	
	dp[0]=0;
	dp[1]=dp[2]=1;
	
	cin>>N;
	
	for(int i=3;i<90;i++)dp[i]=dp[i-1]+dp[i-2];
	bool ok=0;
	vector<ll> ans(3);
	for(int i=0;i<45;i++)
		for(int j=i;j<45;j++)
			for(int k=j;k<45;k++)
				if(dp[i]+dp[j]+dp[k]==N){
					ok=1;
					ans[0]=dp[i];
					ans[1]=dp[j];
					ans[2]=dp[k];
				}
	
	if(ok) cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	else cout<<"I'm too stupid to solve this problem"<<endl;
				
	return 0;
}
