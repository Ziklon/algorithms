#include <iostream>

using namespace std;

int a[11],n,t,k;
long long ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		ans=0;
		for(int j=0;j<t;j++)
			cin>>a[j];
		for(int j=0;j<t;j++){
			cin>>k;
			ans+=k*a[j];
		}
		cout<<ans<<endl;	
	}
	return 0;
}
