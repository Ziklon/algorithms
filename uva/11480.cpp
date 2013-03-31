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

int val(int n){
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			int k=n-i-j;
			if(k<=j)break;
			ans++;
		}
		
	}
	return ans;

}


long long get(int n){
	long long ans=0;
	for(int i=1;i<n;i++){
		int low=i;
		int hih=n;		
		while(low<hih){
			int mid=(hih+low+1)/2;
			int k=n-i-mid;
			if(k>mid){
				low=mid;			
			}else{
				hih=mid-1;
			}				
		}
		ans+=(low-i);
		
	}
	return ans;
}
//Case 1: 1
//Case 1: 1
//Case 2: 4


void solve(){
	int nt=1,N;
	while(scanf("%d",&N)==1&&N){
		printf("Case %d: %lld\n",nt++,get(N));	
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

