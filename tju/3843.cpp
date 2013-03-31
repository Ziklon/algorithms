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
int A[4005],B[160005],M,N;

int binary_search(int n){
	int lo=0;
	int hi=M-1;
	while(lo<hi){
		int mid=(lo+hi)/2;
		if(B[mid]==n)return 1;		
		if(B[mid]>n){
			hi=mid-1;
		}else{
			lo=mid+1;
		}	
	}
	return B[lo]==n;
	
	
}
void solve(){
	scanf("%d %d",&N,&M);
	REP(i,0,N)scanf("%d",&A[i]);
	REP(i,0,M)scanf("%d",&B[i]);
	sort(A,A+N);
	sort(B,B+M);
	int ans=0;
	REP(i,0,N)if(binary_search(A[i]))ans++;
	printf("%d\n",ans);
	
	
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

