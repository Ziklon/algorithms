#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    double ans = 0;
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i) {
        ans += (i * (pow(i / (double)m, n) - pow((i - 1) / (double)m, n )));
    }
    printf("%.13f", ans);
    return 0;
}

