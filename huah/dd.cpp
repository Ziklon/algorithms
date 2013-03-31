#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

int dp[1<<17];

vector<int> toArray(int mask){
	vector<int> ans;
	for(int i=0;i<16;i++){
		int bit=(mask>>i)&1;	
		ans.push_back(bit);			
	}
	return ans;
}
int toInt(vector<int> v){
	int ans=0;
	for(int i=0;i<v.size();i++)
		if(v[i])
			ans|=(1<<i);
	return ans;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


int go(int mask){
	
	if(mask==0)return 0;
	int& ref=dp[mask];
	
	if(ref!=-1)return ref;
	
	ref=1000;
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			int index=(i*4)+j;
			vector<int> v=toArray(mask);
			v[index]^=1;
			ref=min(ref,2+go(toInt(v)));			
			for(int k=0;k<4;k++){
				int xx=i+dx[k];
				int yy=j+dy[k];
				if(min(xx,yy)>=0 && max(xx,yy)<4){
					index=(xx*4)+yy;
					v[index]^=1;
				}
			}
			ref=min(ref,1+go(toInt(v)));			
		}
	
	return ref;	
}

int main(){
	
	//freopen("output","w",stdout);	
	int n,k;
	scanf("%d\n",&n);
	
	memset(dp,-1,sizeof dp);	
	
	
	for(int i=0;i<(1<<16);i++)
		go(i);
	
	
	for (int i = 0; i < n; i++){
		int start=0;
		
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				char cur;
				scanf("%c",&cur);
				int pos=(j*4)+k;
				if(cur=='1')
					start|=(1<<pos);
			}
			scanf("\n");
		}
		cout<<start<<endl;
		cout<<go(start)<<endl;		
	}					
	return 0;
}
