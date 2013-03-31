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
#define INF 1<<30
using namespace std;
int dp[151][151][151],N,D;

int go(int a, int b, int d){
	if(a==0 && b==0) return d==D;
	int& ref=dp[a][b][d];
	if(ref!=-1)return ref;
	ref=0;
	int xx=b-(a-1);
	int yy=b-1 
	
	if(a)ref+=go(a-1,b,d);
	if(b>a)ref+=go(a,b-1,d);
	
	return ref;
	
}


void solve(){

	
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

