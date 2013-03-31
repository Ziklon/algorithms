#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int T,M,x,y,ans;

bool orden(pair<int,int> p, pair<int,int> q){
	if(p.first!=q.first)return p.first<q.first;
	return p.second>q.second;	
}

int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>M;
		vector<pair<int,int> >v;
		while(cin>>x>>y){
			if(x==0 && y==0)break;
			v.push_back(make_pair(x,y));
		}
		
		sort(v.begin(),v.end(),orden);
		
		ans=0;
		
		for(int j=0;j<v.size();j++){
			if(v[j]==)
			
		}
		
		
		
	}
						
	return 0;
}
