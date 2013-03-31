#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double dev;
int n;
int main(){
	while(cin>>n){
		if(n<0)break;
		dev=pow(2.0,-1.0*n);
		printf("2^-%d = %0.3e\n",n,dev);
	}
	return 0;

}
