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
using namespace std;
int G[101][101];
int D[101];
int vis[101];
int N,M,u,v;

int main(){
	freopen("E:/input.txt","r",stdin);
	scanf("%d %d",&N,&M);
	memset(G,0,sizeof G);
	memset(vis,0,sizeof vis);
	for(int i=0;i<M;i++){
		scanf("%d %d",&u,&v);
		G[u][v]=1;
		G[v][u]=1;		
	}
	scanf("%d %d",&u,&v);
	D[u]=0;
	queue<int> Q;
	Q.push(u);
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		if(cur==v){
			cout<<D[cur]<<endl;
			break;
		}	
		for(int i=0;i<=N;i++){
			if(G[cur][i]==1 && !vis[i]){
				vis[i]=1;
				D[i]=D[cur]+1;
				Q.push(i);
			}
		}		
	}
	

}