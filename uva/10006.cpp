#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

bool S[65005];
int N,M;

int powFast(int a, int n){
	if(n==0)return 1;
	int ans=powFast(a,n/2);
	ans=(ans*ans)%N;
	if(n&1)ans=(ans*a)%N;
	return ans%N;
}
int main(){
    // clock_t start = clock();
	 freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	fill(S,0);
	S[0]=S[1]=1;
	for(int i=2;i*i<=65000;i++)
		if(!S[i])
			for(int j=i*i;j<=65000;j+=i)
				S[j]=1;
	

	
	while(scanf("%d",&N)==1 && N){
		M=0;
		
		for(int i=0;i<N;i++){
			if(__gcd(i,N)==1 && powFast(i,N-1)==1)M++;
			
		}
		cout<<N<<" "<<M<<endl;
		// if(!S[N] || N<5)
			// printf("%d is normal.\n",N);
		// else
			// printf("The number %d is a Carmichael number.\n",N);
		
	
	}
	
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
