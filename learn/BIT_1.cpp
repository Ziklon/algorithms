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
#define MAX 16
using namespace std;
int tree[MAX],fre[MAX],n,index;

int read(int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

void update(int idx, int val){
	while(idx<=MAX){
		tree[idx]+=val;
		idx+=(idx&-idx);	
	}
}

void solve(){
	index=1;
	fill(tree,0);
	while(scanf("%d",&n)==1){
		fre[index++]=n;
		update(index-1,n);
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

