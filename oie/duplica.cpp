#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n=0;
	cin>>n;
	while(n){
		int k=0;
		cin >>k;
		while(k){
			long long t=0;
			cin >> t;
			t*=2;
			if(k>1)
				cout <<t<<" ";
			else
				cout << t;
			k--;			
		}
		if(n>1)
			cout<<endl;
		n--;	
	}	
}
