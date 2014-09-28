#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    REP(i, 1 << 20)if(i >= 1) {
        ll tmp = (((i * (i + 1LL)) >> 1) * 3) - i;
        if(tmp <= n && (n - tmp) % 3 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}

