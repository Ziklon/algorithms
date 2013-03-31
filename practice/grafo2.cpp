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
int D[101];
int vis[101];
int N,M,u,v,d;

struct Nodo{
	int x,d;
	Nodo(int a, int b){ x=a;d=b;}
	Nodo(){}
	bool operator < ( const Nodo& p)const{
		return d>p.d;
	}
};
vector<Nodo> G[101];

int dijkstra(int u, int v){
	for(int i=0;i<=N;i++){
		D[i]=1<<20;
	}
	D[u]=0;
	priority_queue<Nodo> Q;
	Q.push(Nodo(u,0));
	while(!Q.empty()){
		Nodo cur=Q.top();Q.pop();
		
		if(cur.x==v)
			return cur.d;
		vector<Nodo>& suc=G[cur.x];
		
		for(int i=0;i<suc.size();i++){
			Nodo hijo=suc[i];
			if((D[hijo.x])>(cur.d+hijo.d)){
				D[hijo.x]=(cur.d+hijo.d);
				Q.push(Nodo(hijo.x, D[hijo.x]));			
			}		
		}		
	}
	return 1<<20;

}

int main(){
	freopen("E:/input.txt","r",stdin);
	scanf("%d %d",&N,&M);

	for(int i=0;i<=N;i++){
		G[i].clear();	
	}
	
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&u,&v,&d);
		G[u].push_back(Nodo(v,d));		
	}
	scanf("%d %d",&u,&v);
	//cout<<u<<" "<<v<<endl;
	int res=dijkstra(u,v);
	cout<<res<<endl;
	

}