#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

#define MAXN 30005


struct node {
    int sum, mini,val;
    node() {}
    node(int _sum, int _mini, int _val) {
        sum = _sum;
        mini = _mini;
        val  = _val;
    }

} tree[MAXN];


ll query(int node, int l, int r, int x, int y) {

    push(node, l, r);

    if(r < x || l > y) return 0;
    ll ans = 0;
    if( x <= l && r <= y)ans += tree[node];
    else {
        int mid  = (l + r) >> 1;
        ans += query(2 * node + 1, l, mid, x, y);
        ans += query(2 * node + 2, mid + 1, r, x, y);
        pull(node);
    }
    return ans;
}

void update(int node, int l, int r, int x, int delta) {
    push(node, l, r);
    if(r < x || l > y) return;


    if(l == r && r == x) {
        tree[node].val= delta;
        tree[node].sum = delta;
        tree[node].mini = delta;                
    } else {
        int mid  = (l + r) >> 1;
        update(2 * node + 1, l, mid, x, y, delta);
        update(2 * node + 2, mid + 1, r, x, y, delta);
        pull(node);
    }

}

int N, Q, x, y, seq[MAXN];

ll sum[MAXN];

int main() {

    cin >> N >> Q;
    for(int i = 0; i < N; ++i)cin >> seq[i];

    sort(seq, seq + N);

    for(int i = 0; i < Q; ++i) {
        cin >> x >> y;
        update(0, 0, N - 1, x - 1, y - 1, 1);
    }

    for(int i = 0; i < N; ++i)sum[i] = query(0, 0, N - 1, i, i);

    sort(sum, sum + N);
    ll ans = 0;
    for(int i = 0; i < N; ++i)ans += (sum[i] * seq[i]);

    cout << ans << endl;

    return 0;
}
