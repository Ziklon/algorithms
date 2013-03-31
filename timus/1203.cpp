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
#define x first
#define y second
using namespace std;
typedef long long ll;
int N,x,y,ans,cur;
pair<int,int> P[100005];

bool orden(const pair<int,int> p,const pair<int,int> q){
	return p.y<q.y;
}
void solve(){
	scanf("%d",&N);
	REP(i,0,N)scanf("%d %d",&P[i].x,&P[i].y);
	sort(P,P+N,orden);
	ans=0;
	cur=0;
	REP(i,0,N){
		if(P[i].x>cur){
			ans++;
			cur=P[i].y;
		}
	}
	printf("%d\n",ans);
	
	
	
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

