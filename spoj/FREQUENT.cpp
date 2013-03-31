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
int A[MAXN],N,M,x,y;

struct pnode{
	int B,L,R;
	pnode(int x, int y, int z){
		B=x;
		L=y;
		R=z;
	}
	pnode(){}
	
}T[MAXN*4];

void build_tree(int node, int a, int b){
	if(a==b)T[node]=pnode(1,1,1);
	else{
		int mid=(a+b)/2,le=(2*node)+1,ri=(2*node)+2;
		build_tree(le,a,mid);
		build_tree(ri,mid+1,b);
		if(A[a]==A[b])T[node]=pnode(b-a+1,b-a+1,b-a+1);
		else if(A[mid]==A[mid+1]){
			T[node]=pnode();
			T[node].B=max(T[le].B,max(T[ri].B,T[le].R+T[ri].L));
			T[node].L=T[le].L;
			T[node].R=T[ri].R;
			if(A[a]==A[mid+1])T[node].L+=T[ri].L;
			if(A[b]==A[mid])T[node].R+=T[le].R;				
		}else{
			T[node]=pnode(max(T[le].B,T[ri].B),T[le].L,T[ri].R);
		}
		//cout<<a<<","<<b<<" "<<T[node].B<<endl;
	}
}

pnode query(int x, int y, int node, int a, int b){
	if(x<=a && b<=y){
		//cout<<a<<"-"<<b<<" "<<T[node].B<<endl;
		return T[node];
	}
	int mid=(a+b)/2,le=(2*node)+1,ri=(2*node)+2;
	
	if(y<=mid)return query(x,y,le,a,mid);
	else if(x>mid)return query(x,y,ri,mid+1,b);
	else{
		a=max(a,x);
		b=min(b,y);
		mid=(a+b)/2;
		pnode ret1=query(x,y,le,a,mid);
		pnode ret2=query(x,y,ri,mid+1,b);
		pnode ret;
		//cout<<a<<" "<<b<<endl;
		if(A[a]==A[b])return pnode(b-a+1,b-a+1,b-a+1);
		else if(A[mid]==A[mid+1]){
			ret.B=max(ret1.B,max(ret2.B,ret1.R+ret2.L));
			ret.L=ret1.L;
			ret.R=ret2.R;
			if(A[a]==A[mid+1])ret.L+=ret2.L;
			if(A[b]==A[mid])ret.R+=ret1.R;
			//cout<<ret1.R<<", "<<a<<" "<<mid<<endl;
			//cout<<"kkaaaaaaa"<<endl;
				
		}else{
			ret.B=max(ret1.B,ret2.B);
			ret.L=ret1.L;
			ret.R=ret2.R;
		}
		//cout<<a<<","<<b<<" "<<T[node].B<<endl;
		return ret;		
	}
}

void solve(){
	while(scanf("%d",&N)==1 && N){
		scanf("%d",&M);
		REP(i,0,N)scanf("%d",&A[i]);		
		build_tree(0,0,N-1);
		REP(i,0,M){
			scanf("%d %d",&x,&y);
			printf("%d\n",query(x-1,y-1,0,0,N-1).B);
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

