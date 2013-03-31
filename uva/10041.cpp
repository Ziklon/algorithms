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
int N,M,X;
vector<int>A;
set<int>S;

int get(int mid){
	int sum=0;
	foreach(A,it)sum+=abs(mid-*it);
	return sum;
}
void solve(){
	scanf("%d",&N);
	REP(t,0,N){
		scanf("%d",&X);
		int sum=INF;
		
		A.resize(X);
		REP(i,0,X){
			scanf("%d",&A[i]);
			S.insert(A[i]);
		}
		sort(all(A));
		int mid=A[A.sz/2];
		sum=get(mid);		
		printf("%d\n",sum);	
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

