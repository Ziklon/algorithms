#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(){	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n=0;
	while(cin>>n){
		int m[n];
		bool ok=true;
		vector<int> v;
		for(int i=0;i<n;i++)
			cin>>m[i];		
		for(int i=0;i<n-1;++i)
			v.push_back(abs(m[i]-m[i+1]));
		sort(v.begin(),v.end());		
		for(int i=v.size()-1;i>=0;--i,--n)
			if((v[i]+1)!=n){
				ok=false;
				break;
			}		 
		if(ok)
			cout << "Jolly"<<endl;
		else
			cout << "Not jolly"<<endl; 
		
	}
	return 0;
}
