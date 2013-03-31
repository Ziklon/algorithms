#include <iostream>
#include <cmath>
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n){
		int a=0;
		long long suma=0;
		cin >>a;		
		while(a){
			int x,y,z;
			cin>>x>>y>>z;
			suma+=x*z;
			a--;		
		}
		cout << suma<< endl;
		n--;
	}
	return 0;
}
