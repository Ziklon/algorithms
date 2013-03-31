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
int num;
vector<int> v;
long long ans;
void combine(int p, int m, int q){
	
	int len1=m-p+1;
	int len2=q-m;
	vector<int> left,right;
	for(int i=0;i<len1;i++)left.push_back(v[i+p]);
	for(int i=0;i<len2;i++)right.push_back(v[i+m+1]);
	
	left.push_back(999999999+10);
	right.push_back(999999999+10);
	int ux=0,uy=0;	
	for(int i=p;i<=q;i++){
		if(left[ux]<=right[uy])
			v[i]=left[ux++];
		else{
			v[i]=right[uy++];
			ans+=len1-ux;
		}	
	}		
}

void merge(int p, int q){
	if(p>=q)return;
	int n=(p+q)/2;
	merge(p,n);
	merge(n+1,q);	
	combine(p,n,q);
}


void solve(){
	while(scanf("%d",&num)==1 && num>0){
		v.resize(num);
		ans=0;		
		REP(i,0,num)scanf("%d",&v[i]);		
		merge(0,v.sz-1);
		printf("%lld\n",ans);
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

