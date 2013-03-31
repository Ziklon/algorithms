#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int N,x,y,t;
int main(){
	ios::sync_with_stdio(0);
	cin>>N;
	vector<int> v(3,0);
	vector<int> u(3,0);
	for(int i=0;i<N;i++){
		cin>>t>>x>>y;
		v[t]+=1;
		u[t]+=x;		
	}
	for(int i=1;i<=2;i++){
			
		if(v[i]*10<=u[i]*2)	
			cout<<"LIVE"<<endl;
		else
			cout<<"DEAD"<<endl;
	}
	return 0;
}
