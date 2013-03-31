#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
int N,T,p,dev,tmp,z;


int main(){
	scanf("%d",&tmp);
	T=0;
	N=tmp;
	dev=1<<30;
	vector<int> v;
	while(tmp--){
		scanf("%d",&p);
		T+=p;
		v.push_back(p);	
	}
	for(int i=1;i<(1<<N);i++){
		tmp=0,z;
		for(int j=0;j<v.size();j++){
			if(i&(1<<j))
				tmp+=v[j];
		}
		z=T-tmp;
		dev=min(dev,abs(z-tmp));
	}
	printf("%d\n",dev);
}
