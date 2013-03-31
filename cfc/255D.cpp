#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

ll calc(ll n){
	return (n*(n+1))/2;
}

int main(){
	ios::sync_with_stdio(false);
	ll n,x,y,c,low=0,hih=1<<30;
	
	while(cin>>n>>x>>y>>c){
		low=0;
		hih=n;	
		while(low+1<hih){
			ll mid=(low+hih)/2;
			ll a=x-max(x-mid,0LL);
			ll b=y-max(y-mid,0LL);
			ll c=min(n,x+mid)-x;
			ll d=min(n,y+mid)-y;
					
			ll sum=calc(a)+calc(b)+calc(c)+calc(d)-(a+b+c+d);
			
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<" - "<<sum<<endl;
			
			
			if(sum>=c)
				hih=mid;
			else
				low=mid+1;
				
		}
		cout<<hih<<endl;
	}		
	return 0;
}
