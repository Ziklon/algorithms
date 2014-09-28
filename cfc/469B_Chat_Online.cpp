#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;

int p, q, l, r;

pair<int, int>  g1[51];

bool seen[1 << 10];

int main() {

    cin >> p >> q >> l >> r;

    REP(i, p) {
        int x, y ;
        cin >> x >> y;
        for(; x <= y; ++x)seen[x] = 1;
    }
    REP(i, q)cin >> g1[i].first >> g1[i].second;

    int ans = 0;
    for(; l <= r; ++l) {
        bool found = 0;
        REP(i, q) {
            for(int x = g1[i].first + l; x <= g1[i].second + l  && x <= 1000; ++x) if(seen[x]) {
                found = 1;
                break;
            }
        }
        if(found)ans++;

    }
    cout << ans << endl;
    return 0;
}

