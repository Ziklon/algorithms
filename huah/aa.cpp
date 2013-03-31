#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> parse(string s){
	istringstream is(s);
	vector<int> v;
	int tmp;
	while(is>>tmp){
		v.push_back(tmp);	
	}	
	return v;
}
int main(){
	
	freopen("output","w",stdout);
	
	
	int n,k;
	scanf("%d\n",&n);
	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin,line);
		scanf("%d\n",&k);
		vector<int> v=parse(line);
		
		sort(v.begin(),v.end());
		
		int ans=0;
		vector<bool> vis(55,0);
		
		
		for (int i = 0; i < v.size(); i++)
		{
			int ubi=-1;
			if(vis[i])continue;
			
			
			for (int j = i+1; j <v.size() ; j++)
			{
				if(vis[j])continue;
				
				if(v[j]==(v[i]*k)){
					ubi=j;
					break;
				}	
			}
			if(ubi!=-1){
				//cout<<v[i]<<" "<<v[ubi]<<endl;
				vis[ubi]=1;
				ans++;	
			}				
		}
		cout<<ans<<endl;				
	}
							
	return 0;
}
