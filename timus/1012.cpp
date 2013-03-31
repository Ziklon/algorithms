#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll dp[181];

int N,K;
int main(){
	ios::sync_with_stdio(0);
	cin>>N>>K;
	dp[1]=K-1;
	dp[2]=(K-1)*(K);

	for(int i=3;i<=N;i++)
		dp[i]=(dp[i-1]+dp[i-2])*(K-1);
	
	
	cout<<dp[N]<<endl;
				
	return 0;
}
