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
using namespace std;
struct Node{
	int x, d;
	Node(int a, int b){ x=a;d=b;}
	Node(){}
};

vector<Node> G[109];
int D[109];
int N,C,x,y,d;

void dfs(int x){		
	REP(i,0,G[x].sz){
		int to=G[x][i].x;
		int dis=min(D[x],G[x][i].d);
		if(D[to]<dis){
			D[to]=dis;
			dfs(to);
		}	
	}
	
}
void solve(){
	int T=1;
	while(scanf("%d %d",&N,&C)==2){
		
		if(N==0 && C==0)break;
		REP(i,0,N+5){
			G[i].clear();
			D[i]=0;
		}
		REP(i,0,C){
			scanf("%d %d %d",&x,&y,&d);
			G[x].push_back(Node(y,d));
			G[y].push_back(Node(x,d));
		}
		scanf("%d %d %d",&x,&y,&d);
		D[x]=INF;
		dfs(x);
		
		int res=D[y]-1;
		int ret=(d+res-1)/res;
		printf("Scenario #%d\n",T);
		printf("Minimum Number of Trips = %d\n",ret);
		printf("\n");
		T++;
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

