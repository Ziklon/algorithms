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
string mapa[55];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int W,H,cnt;
bool vis[55][55],trap[55][55];

void find_traped(){
	REP(i,0,H)REP(j,0,W)if(mapa[i][j]=='T'){
		vis[i][j]=1;
		REP(k,0,4){
			int X=i+dx[k];
			int Y=j+dy[k];
			if(min(X,Y)>=0 && X<H && Y<W)trap[X][Y]=1;			
		}
	}
}

int get_gold(int x, int y){
	queue<pair<int,int> > Q;
	vis[x][y]=1;
	Q.push(make_pair(x,y));
	int ans=0;
	while(!Q.empty()){
		pair<int,int> P=Q.front();Q.pop();
		if(trap[P.first][P.second])continue;		
		REP(i,0,4){
			int X=P.first+dx[i];
			int Y=P.second+dy[i];
			if(min(X,Y)<0 || X>=H || Y>=W  || vis[X][Y] || mapa[X][Y]=='#')continue;			
			if(mapa[X][Y]=='G')ans++;			
			Q.push(make_pair(X,Y));
			vis[X][Y]=1;
		}		
	}
	return ans;
}


void solve(){
	while(scanf("%d %d\n",&W,&H)==2){
		char buff[W+2];
		cnt=0;
		fill(vis,0);
		fill(trap,0);
		
		REP(i,0,H){
			scanf("%s",buff);
			mapa[i]=buff;
		}
		find_traped();
		
		REP(i,0,H)REP(j,0,W)if(mapa[i][j]=='P')cnt=get_gold(i,j);
		
		printf("%d\n",cnt);
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

