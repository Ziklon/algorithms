#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int A[1<<20];
int dp[4001][4001];
int last[1<<20];

int main(){
	
	ios::sync_with_stdio(false);
	int n,ans=0,tmp;
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	memset(last,-1,sizeof last);
		
	ans=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			dp[i][j]=2;
			int same=last[A[j]];
			if(same!=-1)
				dp[i][j]=dp[same][i]+1;
			ans=max(ans,dp[i][j]);
		}
		last[A[i]]=i;
	}
	cout<<ans<<endl;			
	return 0;
}
