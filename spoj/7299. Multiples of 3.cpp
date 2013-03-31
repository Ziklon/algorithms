#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
#define MAXN 110000
#define INF (1<<28)

ll T[4 * MAXN],lazy[4 * MAXN];


void init(int node, int l, int r){
    if(l == r){
        T[node] = 0LL;
    }else{
        int mi = (l + r) >> 1;        
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);        
        T[node] = (T[2 * node + 1]+T[2 * node + 2]);
    }
}

void push(int node, int l, int r){
    T[node] += lazy[node];    
    if(r != l){
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }    
    lazy[node] = 0;
}

void pull(int node){
    T[node] = (T[2 * node + 1]+T[2 * node + 2]);
}

ll query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(r < x || l > y) return 0;
    if(x <= l && r <= y ) return T[node];
    int mi = (l + r) >> 1;
    int ret1 = query(2 * node + 1,l,mi,x,y);
    int ret2 = query(2 * node + 2,mi + 1,r,x,y);    
    pull(node);    
    return ret1+ret2;
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
        memset(T,0,sizeof T);
        memset(lazy,0,sizeof lazy);        
        init(0,0,N);        
        for(int j=0;j<C;j++){
            scanf("%d",&Z);
            if(Z==0){
                scanf("%d %d %d",&p,&q,&v);
                printf("%d-%d %d --\n",p-1,q-1,v);
                //cout<<p<<" "<<q<<" "<<v<<endl;
                update(0,0,N-1,p-1,q-1,v);
            }else{
                scanf("%d %d",&p,&q);
                printf("%lld\n",query(0,0,N-1,p-1,q-1));
            }
            printf("%lld\n",query(0,0,N-1,3,7));
            
        }        
    }
    return 0;
}
