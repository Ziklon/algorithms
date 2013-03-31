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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
#define MAX 1<<20
using namespace std;
int a,b,k;
bool P[1<<20];

void solve(){
	
	fill(P,0);
	P[1]=P[0]=1;
	for(int i=2;i*i<MAX;i++)
		if(P[i]==0)
			for(int j=i*i;j<MAX;j+=i)
				P[j]=1;
	scanf("%d %d %d",&a,&b,&k);
	vector<int> v;
	REP(i,2,MAX)if(P[i]==0)v.push_back(i);
	
	int ans=1<<20;
	int p,q;
	int low=1;
	int hih=b-a+1;
	p=lower_bound(all(v),a)-v.begin();
	q=lower_bound(all(v),b)-v.begin();
	if(P[b])q--;
	
	if((q-p+1)<k){
		puts("-1");
		return;
	}
	
	while(low+1<hih){
		int mid=(low+hih)/2;
		bool ok=1;
		for(int x=a;x<=(b-mid+1);x++){
			p=lower_bound(all(v),x)-v.begin();
			q=lower_bound(all(v),x+mid-1)-v.begin();
			if(P[x+mid-1])q--;
			if((q-p+1)<k)
				ok=0;
		}
		if(ok)
			hih=mid;
		else
			low=mid;		
	}
	printf("%d\n",hih);
	
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

