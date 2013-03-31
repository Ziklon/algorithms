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
int n,m,k, A[11][101][4];

int dp[110][101];


int go(int type, int buy){
	if(type>=m)return 0;
	int& ref=dp[type][buy];
	if(ref!=-1) return ref;
	ref=go(type+1,buy);//not
	
	REP(i,0,n){
		
		
	}
	return ref;
}



void solve(){
	scanf("%d %d %d\n",&n,&m,&k);
	char buff[50];
	
	REP(i,0,n){
		scanf("%s\n",buff);
		//printf("%s\n",buff);
		REP(j,0,m)
			REP(r,0,3)
				scanf("%d",&A[i][j][r]);
		
		scanf("\n");	
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

