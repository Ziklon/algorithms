#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long m,n;
	while(cin>>m>>n){
		cout << abs(m-n)<<endl;
	}
	return 0;
}
