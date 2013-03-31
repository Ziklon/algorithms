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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
char ch;
int M,N;

int D[1000][1000][4];
bool used[1000][1000][4];
char G[1000][1000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

deque<int> Q;

void add_front(int x,int y, int dir, int d){
	if(D[x][y][dir]>d){
		D[x][y][dir]=d;
		Q.push_front(dir);
		Q.push_front(y);		
		Q.push_front(x);
	}
}

void add_back(int x,int y, int dir, int d){
	if(D[x][y][dir]>d){
		D[x][y][dir]=d;
		Q.push_back(x);
		Q.push_back(y);		
		Q.push_back(dir);
	}
}

int main(){	
	
	scanf("%d %d\n",&N,&M);	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%c",&G[i][j]);
		}
		scanf("\n");
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<4;k++){
				D[i][j][k]=INF;
				used[i][j][k]=0;
			}
			
	add_front(N-1,M-1,1,0);

	
	while(!Q.empty()){
		int x=Q[0],y=Q[1],dir=Q[2];
		Q.pop_front();Q.pop_front();Q.pop_front();
		if(used[x][y][dir])continue;
		
		used[x][y][dir]=1;
		int d=D[x][y][dir];
		int x2=x+dx[dir], y2=y+dy[dir];
		
		if(min(x2,y2)>=0 && x2<N && y2<M )add_front(x2,y2,dir,d);
		
		if(G[x][y]=='#'){
			for(int i=0;i<4;i++) if(i!=dir){
				add_back(x,y,i,d+1);
			}
		}	
		
	}
	int ans=D[0][0][1];
	
	if(ans>=INF)cout<<-1<<endl;
	else cout<<ans<<endl;
	
	
	return 0;
}

