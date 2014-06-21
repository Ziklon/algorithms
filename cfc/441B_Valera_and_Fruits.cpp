#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
#define MAXN 3005

int seq[MAXN], n, v, bi, di;

int main() {
    scanf("%d %d", &n, &v);

    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &di, &bi);
        seq[di] += bi;
    }

    int ans = 0;
    for(int day = 1; day <= 3001; ++day) {
        int rem = v;
        int x = min(seq[day - 1], rem);
        rem -= x;
        ans += x;
        x = min(seq[day], rem);
        seq[day] -= x;
        ans += x;
    }
    printf("%d\n", ans);
    return 0;
}
