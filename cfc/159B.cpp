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
vector<int> X[2000];
vector<int> A[2000];

int getEquals(vector<int> &a,vector<int> &b){
	int i=0;
	int j=0;
	int ans=0;
	while(i<a.sz && j<b.sz){
		if(a[i]==b[j]){
			i++;
			j++;
			ans++;
		}else if(a[i]<b[j])i++;
		else j++;
	}
	return ans;
}
void solve(){
	int n,d;
	scanf("%d %d",&n,&d);
	
	REP(i,0,n){
		int a,b;
		scanf("%d %d",&a,&b);
		X[b].push_back(a);		
	}
	REP(i,0,d){
		int a,b;
		scanf("%d %d",&a,&b);
		A[b].push_back(a);		
	}
	REP(i,0,1500){
		sort(all(X[i]));
		sort(all(A[i]));
	}
	int ans=0;
	int res=0;
	REP(i,0,1500){
		int T=min(A[i].sz,X[i].sz);
		ans+=T;
		res+=getEquals(A[i],X[i]);
	}
	cout<<ans<<" "<<res<<endl;
	
	
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

