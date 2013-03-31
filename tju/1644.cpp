#include <iostream>

using namespace std;
int r;
string n,ans;
int main(){
	cin>>r;
	getline(cin,n);
	for(int i=0;i<r;i++){
		getline(cin,n);
		ans="";
		for(int j=n.size()-1;j>=0;j--)
			ans+=n[j];
		cout<<ans<<endl;
		
	}
	return 0;
}
