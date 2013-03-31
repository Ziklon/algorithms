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
int L=100010041;
bool S[50005022];
int saved[10011];
bool check(int n){	
	if(n==2)return 1;
	if(n&1)return S[n>>1]==0;
	return 0;
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
	
	int a,b,c;
	double P,Q;
	saved[0]=0;
	for(int i=1;i<=10003;i++){
		a=i-1;
		c=(a*a)+a+41;
		saved[i]=saved[i-1]+(check(c)?1:0);		
	}
	while(scanf("%d %d",&a,&b)==2){
		Q=b-a+1;
		P=saved[b+1]-saved[a];		
		P=((P*100.0)/Q)+1e-9;
		printf("%.2f\n",P);
	}
	
	// fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
