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
int A[MAXN],x,y,N,M;
struct pnode{
	int left,right,best;
	

}T[MAXN*4];

void build_tree(int node, int a, int b){
	if(a==b)T[node]=1;
	else{
		int mid=(a+b)/2,le=(node*2)+1,ri=(node*2)+2;
		build_tree(le,a,mid);
		build_tree(ri,mid+1,b);
		//T[node]=pnode();
		T[node]=1;
		if(A[a]==A[b])T[node]=max(T[le]+T[ri],T[node]);
		if(A[a]==A[mid])T[node]=max(T[le],T[node]);
		if(A[mid]==A[b])T[node]=max(T[ri],T[node]);		
	}
}

int query(int x, int y, int node, int a, int b){
	if(x<=a && b<=y)return T[node];
	
	int mid=(a+b)/2,le=(node*2)+1,ri=(node*2)+2;
	//cout<<"qqq"<<endl;
	if(y<=mid){
		//cout<<"menor 1"<<endl;
		return query(x,y,le,a,mid);
	}
	else if(x>mid)return query(x,y,ri,mid+1,b);
	else{
		
		int r=query(x,y,le,a,mid);
		int s=query(x,y,ri,mid+1,b);
		int ans=1;
		if(A[a]==A[b])ans=max(ans,T[le]+T[ri]);
		if(A[a]==A[mid])ans=max(ans,T[le]);
		if(A[mid]==A[b])ans=max(ans,T[ri]);		
		return ans;		
	}
}





void solve(){
	scanf("%d %d",&N,&M);
	REP(i,0,N)scanf("%d",&A[i]);
	build_tree(0,0,N-1);
	//REP(i,0,40)printf("%d ",T[i]);
	REP(i,0,M){
		scanf("%d %d",&x,&y);
		//cout<<x<<" "<<y<<endl;
		printf("%d\n",query(x-1,y-1,0,0,N-1));
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

