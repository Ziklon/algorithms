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
		int ans=0;
		vector<int> vis(101,0);
		vector<int> v=parse(line);
		int maxi=0;
		int mini=100;
		
		for (int j = 0; j <v.size() ; j++)
		{
			vis[v[j]]=1;
			maxi=max(maxi,v[j]);
			mini=min(mini,v[j]);
		}
		
		for(int j=mini;j<=maxi;j++)
			ans+=vis[j]==0;
		cout<<ans<<endl;				
	}
							
	return 0;
}
