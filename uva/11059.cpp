#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
int N,A[20];
ll ans=-1LL<<61;

int main(){
	//ios::sync_with_stdio(false);
	int T=1;
	while(cin>>N){
		for(int i=0;i<N;i++)cin>>A[i];
		
		ans=0;
		for(int i=0;i<N;i++)
			for(int j=i;j<N;j++){
				ll tmp=1;
				for(int k=i;k<=j;k++){
					tmp*=A[k];
				}
				ans=max(ans,tmp);
			}
		cout<<"Case #"<<T<<": The maximum product is "<<ans<<"."<<endl;
		cout<<endl;
		T++;	
		
	}					
	return 0;
}
