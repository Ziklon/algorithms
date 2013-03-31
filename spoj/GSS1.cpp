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
#define MAXN 50002
using namespace std;
struct pnode{
	int best,left,right,sum;
	pnode(){}
	pnode(int x, int y, int z,int s){
		best=x;
		left=y;
		right=z;
		sum=s;
	}

}T[MAXN*4];
int A[MAXN],N,M,x,y;

void build_tree(int node, int a, int b){
	if(a==b){
		T[node]=pnode(A[a],A[a],A[a],A[a]);
	}else{
		int mid=(b+a)/2,le=(2*node)+1,ri=(2*node)+2;		
		build_tree(le,a,mid);
		build_tree(ri,mid+1,b);
		T[node]=pnode();
		T[node].sum=T[le].sum+T[ri].sum;
		T[node].best=max(T[le].best,max(T[le].right+T[ri].left,T[ri].best));
		T[node].left=max(T[le].left,T[le].sum+T[ri].left);		
		T[node].right=max(T[ri].right,T[ri].sum+T[le].right);	
	}
}

pnode query(int x, int y, int node, int a, int b){
	if(x<=a && b<=y)return T[node];
	int mid=(b+a)/2,le=(2*node)+1,ri=(2*node)+2;
	if(y<=mid)return query(x,y,le,a,mid);
	else if(x>mid)return query(x,y,ri,mid+1,b);
	else{
		pnode ret1=query(x,y,le,a,mid);
		pnode ret2=query(x,y,ri,mid+1,b);
		pnode ret;
		ret.sum=ret1.sum+ret2.sum;
		ret.best=max(ret1.best,max(ret1.right+ret2.left,ret2.best));
		ret.left=max(ret1.left,ret1.sum+ret2.left);
		ret.right=max(ret2.right,ret2.sum+ret1.right);		
		return ret;
	}
}


void solve(){
	scanf("%d %d",&N);
	REP(i,0,N)scanf("%d",&A[i]);
	build_tree(0,0,N-1);
	scanf("%d",&M);	
	
	REP(i,0,M){
		scanf("%d %d",&x,&y);
		x--;y--;
		printf("%d\n",query(x,y,0,0,N-1).best);	
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

