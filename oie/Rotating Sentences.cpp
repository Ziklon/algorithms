#include <iostream>
#include <cmath>
#include <sstream>
#include  <vector>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	vector<string> v;
	string s="a";
	int lg=0;
	while(s.size()>0){
		getline(cin,s);
		lg=max(lg,(int)s.size());
		if(s.size())
			v.push_back(s);	
	}
	for(int i=0;i<lg;i++){
		for(int j=v.size()-1;j>=0;j--){
			if(v[j].size()>=i+1)
				cout<<v[j][i];
			else
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
