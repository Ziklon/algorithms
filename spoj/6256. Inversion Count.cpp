#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 200000
int tree[MAXN + 1];
int a[MAXN], b[MAXN];

void update(int idx, int val) {
    for(int x = idx; x <= MAXN; x += x & -x)
        tree[x] += val;
}

int query(int idx) {
    int ans = 0;
    for(int x  = idx; x > 0; x -= x & -x)ans += tree[x];
    return ans;
}


int main() {
    //freopen("in.txt","r",stdin);    
    int T, N, K;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + N);
        memset(tree,0,sizeof tree);
        long long cnt_inv = 0;
        for(int i = 0; i < N; ++i) {
            int idx = 1 + (lower_bound(b, b + N, a[i]) - b);
            cnt_inv +=  i - query(idx);
            update(idx, 1);
        }
        printf("%lld\n",cnt_inv);
    }


}
