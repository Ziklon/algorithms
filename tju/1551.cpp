#include <iostream>
#include <cstdio>
using namespace std;

int f(int n){
	int d=0;
	while(n){
		d+=n%10;
		n/=10;
	}
	return d;

}
long long N,Q;
string line;
int main(){

	while(cin>>line){
		if(line.size()==1 && line[0]=='0')break;
		N=0;
		for(int i=0;i<line.size();i++)
			N+=line[i]-'0';
		while(N>=10)
			N=f(N);
		printf("%lld\n",N);	
	}
	return 0;


}
