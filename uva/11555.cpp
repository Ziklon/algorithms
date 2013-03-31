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
int N,L,W,M,R,X;
int A[4005];
int cur;

bool cmpOne(int a, int b){
	return abs(cur-a)>abs(cur-b);
}
bool cmpTwo(int a, int b){
	return hypot(abs(cur-a),W)>hypot(abs(cur-b),W);
}


void solve(){
	while(scanf("%d",&N)==1){
		scanf("%d %d",&L,&W);
		vector<int>v;
		cur=0;
		REP(i,0,N){
			scanf("%d",&X);
			v.push_back(X);
		}
		M=N/2;
		R=L/(M-1);		
		double ans=0;
		REP(i,0,M){
			sort(all(v),cmpOne);
			int p=v.back();v.pop_back();
			sort(all(v),cmpTwo);
			int q=v.back();v.pop_back();
			ans+=abs(p-cur)+hypot(abs(cur-q),W);
			cur+=R;
		}
		printf("%.10lf\n",ans);
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

