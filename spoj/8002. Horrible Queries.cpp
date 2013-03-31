#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
#define MAXN 110000
#define INF (1<<28)

ll tree[4 * MAXN],lazy[4 * MAXN];


void push(int node, int l, int r){
    tree[node] += lazy[node]*(r-l+1);    
    if(r != l){
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }    
    lazy[node] = 0;
}

void pull(int node){
    tree[node] = (tree[2 * node + 1]+tree[2 * node + 2]);
}

ll query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(r < x || l > y) return 0;
    ll ret=0;
    if(x <= l && r <= y ) ret+=tree[node];
    else{
        int mi = (l + r) >> 1;
        ret+= query(2 * node + 1,l,mi,x,y);
        ret+= query(2 * node + 2,mi + 1,r,x,y);    
        pull(node);        
    }        
    return ret;
}

void update(int node, int l, int r, int x, int y, int val){
    push(node,l,r);    
    if(r < x || l > y) return;    
    if(x <= l && r <= y){
        lazy[node] += val;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;        
        update(2 * node + 1,l,mi,x,y,val);
        update(2 * node + 2,mi + 1,r,x,y,val);        
        pull(node);
    }
}

int N,M,p,q,v,C,Z;

int main(){
    #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
    #endif
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&N,&C);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        for(int j=0;j<C;j++){
            scanf("%d",&Z);
            if(Z==0){
                scanf("%d %d %d",&p,&q,&v);
                update(0,0,N-1,p-1,q-1,v);
            }else{
                scanf("%d %d",&p,&q);
                printf("%lld\n",query(0,0,N-1,p-1,q-1));
            }            
        }        
    }
    return 0;
}
