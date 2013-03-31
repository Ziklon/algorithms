#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> v;
int dp[50][1000];

int go(int p,int x){
	int dev=0;
	for(int i=p+1;i<v.size();i++){
		if(v[i]>x)
			dev=max(dev,1+go(i,v[i]));
	}
	return dev;
}

int main(){
	int n=0;
	v.clear();
	while(cin>>n){
		v.push_back(n);
	}
	int dev=0;
	for(int i=0;i<v.size();i++)
		dev=max(dev,1+go(i,v[i]));
	cout<<dev<<endl;
	return dev;
}
