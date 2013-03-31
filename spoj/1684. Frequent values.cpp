#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 100001
using namespace std;
typedef long long ll;

int start[MAX],cnts[MAX],A[MAX],n,q,tmp,x,y;
int tree[4*MAX];
void build_tree(int node, int a, int b){
	if(a==b)tree[node]=1;
	else{
		int mid=(b+a)/2,le=(2*node)+1,ri=(2*node)+2;		
		build_tree(le,a,mid);
		build_tree(ri,mid+1,b);
		int ret=max(tree[le],tree[ri]);
		if(A[mid]==A[mid+1]){
			int stTmp=max(a,start[mid]);
			int endTmp=min(b,start[mid]+cnts[mid]-1);		
			ret=max(ret,endTmp-stTmp+1);
		}
		tree[node]=ret;
	}
}

int query(int x, int y, int node, int a, int b){
	if(x<=a && b<=y)return tree[node];	
	int mid=(b+a)/2,le=(2*node)+1,ri=(2*node)+2;
	if(y<=mid)return query(x,y,le,a,mid);
	else if(x>mid)return query(x,y,ri,mid+1,b);
	else{
		int ret1=query(x,y,le,a,mid);
		int ret2=query(x,y,ri,mid+1,b);
		int ret=max(ret1,ret2);
		if(A[mid]==A[mid+1]){
			int stTmp=max(x,start[mid]);
			int endTmp=min(y,start[mid]+cnts[mid]-1);
			ret=max(ret,endTmp-stTmp+1);
		}	
		return ret;
	}	
}




int main(){
	//ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	while(scanf("%d",&n) && n!=0){
		scanf("%d",&q);
		map<int,int>M;
		int tmp=0;		
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			if(M.count(A[i])==0)tmp=i;
			start[i]=tmp;
			M[A[i]]++;
		}		
		for(int i=0;i<n;i++){			
			if(i==start[i])tmp=M[A[i]];
			cnts[i]=tmp;				
		}
		build_tree(0,0,n-1);
		for(int i=0;i<q;i++){
			scanf("%d %d",&x,&y);
			x--;y--;
			printf("%d\n",query(x,y,0,0,n-1));		
		}		
	}
	return 0;
}
