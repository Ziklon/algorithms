#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,K,liz;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>N){
		cin>>M;
		vector<int> v(10,0);
		for(int i=0;i<M;i++){
			cin>>K;
			v[K]++;
		}
		bool ok=0;
		for(int x=1;x<=900000&&!ok;x++){
			int aux=x*N;
			ok=1;
			while(aux){
				if(v[aux%10]==0)
					ok=0;
				aux/=10;
			}
			if(ok){
				cout<<(x*N)<<endl;
				break;
			}
		}
		if(!ok){
			cout<<0<<endl;
		}
	}
	return 0;
}