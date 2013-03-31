#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define INF 1<<20
using namespace std;
typedef long long ll;

int dp[125][125];
int B[125],K,tmp;
double R;

int go(int index, int cnt){
	if(index>=K)return cnt;
	int& ref=dp[index][cnt];
	if(ref!=-1)return ref;
	ref=INF;
	for(int i=index;i<K;i++){
		if(R*B[index]>=B[i]){
			ref=min(ref,go(i+1,cnt+1));
		}
		else
			break;
			
	}
	return ref;
}

int main(){
	//ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);	
	while(cin>>K>>R && K){
		for(int i=0;i<K;i++)cin>>B[i]>>tmp;		
		sort(B,B+K);
		memset(dp,-1,sizeof dp);
		cout<<go(0,0)<<endl;			
	}
	return 0;
}
