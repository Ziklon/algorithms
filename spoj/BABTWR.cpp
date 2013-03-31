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
int dp[33],N;
vector<int> A[35];

int go(int index){
	
	int& ref=dp[index];
	if(ref!=-1)return ref;
	ref=0;
	sort(all(A[index]));
	
	
	do{
		REP(i,0,N){
			if(i!=index){
				sort(all(A[i]));
				
				do{
					if(A[index][0] > A[i][0] && A[index][1]>A[i][1]){
						ref=max(ref,go(i)+A[i][2]);
					
					}
				
				}while(next_permutation(all(A[i])));			
			
			}
		
		}
	
	}while(next_permutation(all(A[index])));
	return ref;

}


void solve(){
	while(scanf("%d",&N)==1 && N){
		
		REP(i,0,N){
			A[i].resize(3);
			REP(j,0,3)scanf("%d",&A[i][j]);
			sort(all(A[i]));
		}
		int ans=0;
		fill(dp,-1);
		REP(i,0,N){
			ans=max(A[i][2]+go(i),ans);		
		}
		printf("%d\n",ans);
		
	
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

