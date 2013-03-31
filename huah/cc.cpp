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
		vector<int> chany=parse(line);
		getline(cin,line);		
		vector<int> pc=parse(line);		
		sort(chany.begin(),chany.end());
		sort(pc.begin(),pc.end());
		
		int ans=0;
		vector<int> vis(55,0);
		
		
		for (int j = chany.size()-1; j >=0 ; j--)
		{
			int index=-1;			
			for(int k=pc.size()-1;k>=0;k--){
				if(pc[k]<chany[j] && vis[k]==0){
					index=k;
					break;
				}					
			}
			if(index!=-1){
				vis[index]=1;
				
				ans+=chany[j];	
			}	
				
		}
		cout<<ans<<endl;		
						
	}
							
	return 0;
}
