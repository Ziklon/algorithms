#include <iostream>

using namespace std;
int n,r,ans;
int main(){
	cin>>r;
	for(int i=0;i<r;i++){
		cin>>n;
		ans=0;
		while(n){
			ans+=n%10;
			n=n/10;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
