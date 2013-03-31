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
int m,n,t;

int dp1[10005];
int A[3];
int go(int sum){
	if(sum==0)return 0;
	int& ref=dp1[sum];
	if(ref!=-1)return ref;
	ref=(-1<<20);
	REP(i,0,2){
		if(sum>=A[i])
			ref=max(ref,1+go(sum-A[i]));
	}
	return ref;
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d %d",&m,&n,&t)==3){
		
		A[0]=m;
		A[1]=n;
		fill(dp1,-1);

		int res=t;
		while(go(res)<0){
			res-=1;
		}
		int ans=go(res);
		if(res==t)printf("%d\n",ans);
		else printf("%d %d\n",ans,t-res);

	
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
