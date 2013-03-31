#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#define INF 1<<20
using namespace std;

typedef long long ll;

int dp[11][1<<11],N,x,y,xs,ys,M;
int dis[11][11];

int go(int index, int mask){
	if(__builtin_popcount(mask)==M)return dis[0][index];
	int& ref=dp[index][mask];
	if(ref!=-1)return ref;
	ref= INF;
	for(int i=1;i<=M;i++)if((mask&(1<<i))==0){
		ref=min(ref,dis[index][i]+go(i,mask|(1<<i)));
	}
	return ref;	
}

int main(){
	ios::sync_with_stdio(false);
	
	cin>>N;
	for(int t=0;t<N;t++){
		cin>>x>>y;
		cin>>xs>>ys;
		cin>>M;		
		vector<pair<int,int> > v(M+1);
		v[0].first=xs;
		v[0].second=ys;
		for(int i=1;i<=M;i++)cin>>v[i].first>>v[i].second;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<=M;i++)
			for(int j=0;j<i;j++)
				dis[i][j]=dis[j][i]=abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
				
		int ans=go(0,0);
		printf("The shortest path has length %d\n",ans);		
		
	}
			
	return 0;
}
