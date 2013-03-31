#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	int T,N,M,tmp;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>N>>M;
		int winA=0;
		int winB=0; 
		for(int i=0;i<N;i++)cin>>tmp,winA=max(winA,tmp);
		for(int i=0;i<M;i++)cin>>tmp,winB=max(winB,tmp);
		
		if(winA>=winB)cout<<"Godzilla"<<endl;
		else cout<<"MechaGodzilla"<<endl;			
	}
	
	return 0;
}
