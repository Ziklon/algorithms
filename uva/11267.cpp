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
int P[205];
int vis[205];
int N,E;
vector<int> G[205];
struct node{
	int x, y,c;
	node(){}
	node(int _x, int _y, int _c){
		x=_x;
		y=_y;
		c=_c;
	}
	bool operator <(node p)const{
		return p.c>c;
	}
};

int find(int node){
	if(P[node]==node)return node;
	P[node]=find(P[node]);
	return P[node];
}
void join(int p, int q){
	P[find(p)]=find(q);
}
void dfs(int node){
	vis[node]=1;
	REP(i,0,G[node].sz)
		if(!vis[G[node][i]])
			dfs(G[node][i]);
}

int countG(){
	int ans=0;
	REP(i,0,N)
		ans+=vis[i+1];
	return ans;
}


vector<node> Ed;

int main(){
    //clock_t start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&N)==1 && N){
		scanf("%d",&E);
		int x,y,c;
		Ed.clear();
		REP(i,0,N){
			vis[i+1]=0;
			G[i+1].clear();
		}
		REP(i,0,E){
			scanf("%d %d %d",&x,&y,&c);
			Ed.push_back(node(x,y,c));
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1);
		if(countG()!=N){
			printf("Invalid data, Idiot!\n");
			continue;
		}
		sort(all(Ed));
		REP(i,0,N)P[i+1]=i+1;
		int ans=0;
		int num=0;
		REP(i,0,E){
			if(find(Ed[i].x)!=find(Ed[i].y)){
				join(Ed[i].x,Ed[i].y);
				ans+=Ed[i].c;
				num++;
			}
		}
		cout<<num<<" ";
		printf("%d\n",ans);
		
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
