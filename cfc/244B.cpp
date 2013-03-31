#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;


int bits(int n){
	int ans=0;
	while(n){
		n/=2;
		ans++;
	}
	return ans;
}



int main(){
	ll n,tmp,ans;
	cin>>n;
	ans=0;
	set<int> S;
	
	for(int a=0;a<10;a++)
		for(int b=0;b<10;b++){
			for(int mask=0;mask<(1<<10);mask++){
				int nb=bits(mask);
				tmp=0;
				for(int i=0;i<nb;i++){
					if(mask&(1<<i))
						tmp=(tmp*10)+b;
					else
						tmp=(tmp*10)+a;
				}
				if(tmp>0 && tmp<=n){
					S.insert((int)tmp);				
				}
			}
		}
	
	
	cout<<S.size()<<endl;
				
	return 0;
}
