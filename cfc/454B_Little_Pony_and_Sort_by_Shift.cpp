#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
#define MAXN 100005
int n, seq[MAXN];
int dp1[MAXN];
int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)scanf("%d", seq + i);


    dp1[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(seq[i] >= seq[i - 1])
            dp1[i] = dp1[i - 1] + 1;
        else
            dp1[i] = 1;
    }
    int ans = n + 5;
    if(dp1[n] == n)ans = 0;

    for(int i = 1; i < n; ++i) {
        if( seq[1] >= seq[n] && dp1[i] == i &&  dp1[n] == n - i) {
            ans = min(n - i, ans);
        }
    }
    printf("%d\n", ans > n ? -1 : ans);
    return 0;
}

