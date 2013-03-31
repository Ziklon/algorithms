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
int L=1000000,X,a,Y;
bool S[500005];
bool isPrime(int n){
	if(n==2)return 1;
	if((n&1) && n>2)return S[n>>1]==0;
	return 0;
}

bool check(int n){	
	X=0;
	Y=n;
	while(n>0){
		X=(X*10)+n%10;
		n/=10;
	}
	return X!=Y&&isPrime(X);
}

int main(){
    // clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	fill(S,0);
	
	for(int j=3;j*j<=L;j+=2)
		if(S[j>>1]==0)
			for(int k=j*j;k<=L;k+=(j*2))
				S[k>>1]=1;
	
	
	while(scanf("%d",&a)!=EOF){
		if(!isPrime(a))
			printf("%d is not prime.\n",a);
		else if(check(a))
			printf("%d is emirp.\n",a);
		else printf("%d is prime.\n",a);
	}
	
	// fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
