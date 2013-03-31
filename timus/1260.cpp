#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll dp[60];
int N;
int main(){
	ios::sync_with_stdio(0);
	cin>>N;
	
	dp[1]=1;
	dp[2]=1;
	dp[3]=2;
	for(int i=4;i<=N;i++)
		dp[i]=dp[i-1]+dp[i-3]+1;
		
	cout<<dp[N]<<endl;				
	return 0;
}
