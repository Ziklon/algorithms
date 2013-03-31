#include <iostream>

using namespace std;

int sum(int n){
	int dev=0;
	while(n){
		dev+=n%10;
		n/=10;
	}
	return dev;
}

int main(){
	int n,m,r;
	cin>>n;
	while(n--){
		cin>>m;
		r=0;
		for(int i=1;i<m;i++)
		    if(i+sum(i)==m){
		        r=i;
		        break;
			}
		cout<<r<<endl;
	}
	return 0;
}