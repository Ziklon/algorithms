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
#define MAXN 100005
using namespace std;
int A[MAXN],N,x,y,M;
char op;
struct pnode{
	int p,q;
	pnode(){}
	pnode(int x, int y){
		p=x;
		q=y;
	}
}T[MAXN*4];

void built_tree(int node, int a, int b){
	if(a==b)T[node]=pnode(A[a],0);
	else{
		int mid=(a+b)/2,le=(2*node)+1,ri=(2*node)+2;
		built_tree(le,a,mid);
		built_tree(ri,mid+1,b);
		int B[]={T[ri].p,T[ri].q,T[le].p,T[le].q};
		sort(B,B+4);
		T[node]=pnode(B[2],B[3]);		
	}
}
pnode query(int x, int y, int node, int a, int b){
	if(x<=a && b<=y)return T[node];
	int mid=(a+b)/2,le=(2*node)+1,ri=(2*node)+2;
	if(y<=mid)return query(x,y,le,a,mid);
	else if(x>mid) return query(x,y,ri,mid+1,b);
	else{
		pnode ret1=query(x,y,le,a,mid);
		pnode ret2=query(x,y,ri,mid+1,b);
		int B[]={ret1.p,ret1.q,ret2.p,ret2.q};	
		sort(B,B+4);		
		return pnode(B[2],B[3]);
	}
	
}

void update(int x, int val, int node, int a, int b){
	if(x<a || x>b)return;
	
	if(a==b)T[node]=pnode(val,0);
	else{
		int mid=(a+b)/2,le=(2*node)+1,ri=(2*node)+2;
		update(x,y,le,a,mid);
		update(x,y,ri,mid+1,b);
		int B[]={T[ri].p,T[ri].q,T[le].p,T[le].q};
		sort(B,B+4);
		T[node]=pnode(B[2],B[3]);
	}

}



void solve(){
	scanf("%d",&N);
	REP(i,0,N)scanf("%d",&A[i]);
	scanf("%d\n",&M);
	
	built_tree(0,0,N-1);
	pnode res;
	
	REP(i,0,M){
		scanf("%c %d %d\n",&op,&x,&y);
		if(op=='Q'){
			res=query(x-1,y-1,0,0,N-1);
			printf("%d\n",(res.p+res.q));
		}else{
			update(x-1,y,0,0,N-1);
		}		
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

