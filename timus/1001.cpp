
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

double N;
int main(){
	vector<double> v;
	while(cin>>N)
		v.push_back(N);	
	for(int i=v.size()-1;i>=0;i--){
		N=sqrt(v[i]);
		printf("%.4f\n",N);
	}
	return 0;

}
