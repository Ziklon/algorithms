#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

#define MAXN 30010

char s[MAXN];

#define mvLeft(node) 2*node + 1
#define mvRight(node) 2*node + 2

struct node {
    int need_open;
    int need_close;
    node() {
        need_open = need_close=0;
    }
    node(int _open, int _close) {
        need_open = _open;
        need_close = _close;
    }

} tree[4 * MAXN];


void init_tree(int pnode, int l, int r) {
    if(l == r) { // leaft nodes
        if(s[l] == '(') tree[pnode] = node(0, 1);
        else tree[pnode] = node(1, 0);
    } else {
        int mid = (l + r) >> 1;
        init_tree(mvLeft(pnode) , l, mid);
        init_tree(mvRight(pnode) , mid + 1, r);
        int closing = min(tree[mvLeft(pnode)].need_close, tree[mvRight(pnode)].need_open);
        tree[pnode].need_close = tree[mvLeft(pnode)].need_close + tree[mvRight(pnode)].need_close - closing;
        tree[pnode].need_open = tree[mvLeft(pnode)].need_open + tree[mvRight(pnode)].need_open - closing;
    }
}

void update(int pnode, int l, int r, int idx) {
    if(l == r) {
        if(s[idx] == '(') {
            tree[pnode]=node(1,0);
            s[idx] = ')';
        } else {
            tree[pnode]=node(0,1);
            s[idx] = '(';
        }
    } else {
        int mid = (l + r) >> 1;
        if(idx <= mid)update(mvLeft(pnode), l, mid, idx);
        else update(mvRight(pnode), mid + 1, r, idx);
        int closing = min(tree[mvLeft(pnode)].need_close, tree[mvRight(pnode)].need_open);
        tree[pnode].need_close = tree[mvLeft(pnode)].need_close + tree[mvRight(pnode)].need_close - closing;
        tree[pnode].need_open = tree[mvLeft(pnode)].need_open + tree[mvRight(pnode)].need_open - closing;
    }
}




int main() {
    //freopen("input", "r", stdin);
    int n, q, t;
    for(int te = 1; te <= 10; ++te) {
        printf("Test %d:\n", te);
        scanf("%d", &n);
        scanf("%s", s);
        scanf("%d", &q);
        init_tree(0, 0, n - 1);        
        for(int i = 0; i < q; ++i) {
            scanf("%d", &t);
            if(t == 0) {
                if(tree[0].need_close == 0 && tree[0].need_open == 0)printf("YES\n");                
                else printf("NO\n");
            } else {
                update(0, 0, n - 1, t - 1);
            }
        }
    }
    return 0;
}
