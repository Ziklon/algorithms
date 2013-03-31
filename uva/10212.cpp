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
#define oo 1<<30
using namespace std;
int N,M;
int R,i,S;

void solve(){
	while(scanf("%d %d\n",&N,&M)==2){
		int a=0,b=0,n;
		
		R=1;
		M=N-M+1;		
		for(i=M;i<=N;i++){
			n=i;
			while((n&1)==0){
				n>>=1;
				a++;
			}
			while(n%5==0){
				n=n/5;
				b++;
			}
			R=(R*n)%10;
			
		}
		
		for(i=b;i<a;i++)R=(R<<1)%10;
		for(i=a;i<b;i++)R=(R*5)%10;
		R=R%10;
		printf("%d\n",R);
	
	}
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

