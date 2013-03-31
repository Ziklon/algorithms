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
#define INF 1<<27
#define MAX 1001
using namespace std;
struct Node{
	int x, f,w;
	Node(int a, int b, int s){ x=a;f=b;w=s;}
	Node(){}
	bool operator < (const Node& p)const{
		return w>p.w;
	}
};
int P[MAX],N,M,x,y,d,q,res;
vector<Node> G[MAX];

int D[1000][101];

int dijkstra(int x, int y, int c){
	REP(i,0,N){
		REP(j,0,c+1)
			D[i][j]=INF;
	}
	priority_queue<Node>Q;
	D[x][0]=0;
	Q.push(Node(x,0,0));
	while(!Q.empty()){
		Node u=Q.top();Q.pop();
		if(u.x==y)
			return u.w;
		
		if(D[u.x][u.f]<u.w)continue;

		if(u.f<c && D[u.x][u.f+1]>(u.w+P[u.x])){
			Q.push(Node(u.x, u.f+1 , u.w+P[u.x]));
			D[u.x][u.f+1]=u.w+P[u.x];	
		}
		vector<Node>& v=G[u.x];
		REP(i,0,v.sz){
			if(v[i].f>u.f)continue;
			int dist=v[i].f;
			int neight=v[i].x;
			if(dist<=u.f){
				int newFuel=u.f-dist;
				if(D[neight][newFuel]>u.w){
					D[neight][newFuel]=u.w;
					Q.push(Node(neight,newFuel,u.w));
				}			
			}
		}	
	}
	return INF;
}

void solve(){
	scanf("%d %d",&N,&M);
	REP(i,0,N)scanf("%d",&P[i]);
	
	REP(i,0,M){
		scanf("%d %d %d",&x,&y,&d);
		
		G[x].push_back(Node(y,d,0));
		G[y].push_back(Node(x,d,0));		
	}
	
	scanf("%d",&q);
	REP(i,0,q){
		scanf("%d %d %d",&d,&x,&y);		
		res=dijkstra(x,y,d);
		if(res>=INF)
			printf("impossible\n");
		else
			printf("%d\n",res);
		
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

