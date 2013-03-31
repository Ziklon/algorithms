#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define MAX 1000000

using namespace std;
typedef long long ll;
int A[500][500],B[500][500],m,n;
bool P[MAX];


int main(){
	//freopen("input","r",stdin);
	memset(P,0,sizeof P);
	for(int i=2;i*i<=MAX;i++)if(P[i]==0)for(int j=i*i;j<MAX;j+=i)P[j]=1;
	
	vector<int> primes;
	for(int i=2;i<MAX;i++)if(P[i]==0)primes.push_back(i);
	
	while(scanf("%d %d",&n,&m)==2){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&A[i][j]);
				int idx=lower_bound(primes.begin(),primes.end(),A[i][j])-primes.begin();
				B[i][j]=primes[idx]-A[i][j];	
			}
		int ans=1<<30;
		for(int i=0;i<n;i++){
			int aa=0;
			for(int j=0;j<m;j++)aa+=B[i][j];
			ans=min(ans,aa);
		}
		for(int j=0;j<m;j++){
			int aa=0;
			for(int i=0;i<n;i++)aa+=B[i][j];
			ans=min(ans,aa);
		}
		cout<<ans<<endl;		
	}	
	return 0;
}

