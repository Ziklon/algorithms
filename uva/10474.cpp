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
vector<int>v;
int N,Q,ans,ubi,x;

int get(int x){
	int lo=0;
	int hi=v.sz-1;
	while(lo<hi){
		int mid=(hi+lo)/2;
		if(v[mid]>=x)
			hi=mid;
		else 
			lo=mid+1;
	}
	if(v[lo]==x)return lo;
	return -1;
}



void solve(){
	int C=1;
	while(scanf("%d %d",&N,&Q)==2){
		if(N==Q && N==0)break;
		v.resize(N);
		REP(i,0,N)scanf("%d",&v[i]);		
		sort(all(v));
		printf("CASE# %d:\n",C++);		
		REP(i,0,Q){
			scanf("%d",&x);
			ubi=get(x);
			if(ubi>-1)printf("%d found at %d\n",x,ubi+1);
			else printf("%d not found\n",x);	
		}
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

