#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
#define NMAX 100
int A[NMAX],N,C,X,Y;

int tree[4*NMAX];

void build_tree(int node, int a, int b){
    if(a==b)tree[node]=A[a];
    else{
        int mid=(a+b)/2;
        int le=(2*node)+1;
        int ri=(2*node)+2;
        build_tree(le,a,mid);
        build_tree(ri,mid+1,b);
        tree[node]=max(tree[le],tree[ri]);
    }
}

int query(int x, int y,int node, int a, int b){
    if(x<=a && b<=y)return tree[node];
    int mid=(a+b)/2;
    int le=(2*node)+1;
    int ri=(2*node)+2;
    if(y<=mid)return query(x,y,le,a,mid);
    
    else if(x>mid)return query(x,y,ri,mid+1,b);    
    else{
        int resa=query(x,y,le,a,mid);
        int resb=query(x,y,ri,mid+1,b);
        return max(resa,resb);   
    }
}

void update(int x, int val, int node, int a, int b){
    if(x<a || x>b)return;    
    if(a==b)tree[node]=val;
    else{
        int mid=(a+b)/2;
        int le=(2*node)+1;
        int ri=(2*node)+2;
        update(x,val,le,a,mid);
        update(x,val,ri,mid+1,b);
        tree[node]=max(tree[le],tree[ri]);            
    }
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&N);
   for(int i=0;i<N;i++)scanf("%d",&A[i]);   
   
   build_tree(0,0,N-1);
   while(scanf("%d %d %d",&C,&X,&Y)==3){  
        if(C==1)
            printf("%d\n",query(X,Y,0,0,N-1));    
        else{           
            update(X,Y,0,0,N-1);
        }
   } 
   return 0;      
}
