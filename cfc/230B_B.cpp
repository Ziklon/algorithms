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
#define MAX 1000000
using namespace std;
bool A[MAX+3];
int n;
long long M;

void solve(){
	fill(A,1);
	
	for(int i=2;i*i<=MAX;i++){
		if(A[i])
			for(int j=i*i;j<=MAX;j+=i)
				A[j]=0;
	}
	vector<long long> v;
	
	REP(i,2,MAX)if(A[i])v.push_back((1LL*i)*i);
	
	cin>>n;
	REP(i,0,n){
		cin>>M;
		if(binary_search(all(v),M))
			puts("YES");
		else puts("NO");
	}
	
	
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

