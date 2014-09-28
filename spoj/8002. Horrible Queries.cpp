#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()

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

int N, Q, x, y, seq[MAXN];

ll sum[MAXN];

int main(){
    #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
    #endif
   freopen("input", "r", stdin);
    //memset(tree,0,sizeof tree);
    //memset(lazy,0,sizeof lazy);

    cin >> N >> Q;
    for(int i = 0; i < N; ++i)cin >> seq[i];

    sort(seq, seq + N);

    for(int i = 0; i < Q; ++i) {
        cin >> x >> y;
        update(0, 0, N - 1, x - 1, y - 1, 1LL);
    }

    for(int i = 0; i < N; ++i) sum[i] = query(0, 0, N - 1, i, i);

    sort(sum, sum + N);

    ll ans = 0;
    for(int i = 0; i < N; ++i) ans += ((sum[i]) * seq[i]);
    cout << ans << endl;
    return 0;
}
