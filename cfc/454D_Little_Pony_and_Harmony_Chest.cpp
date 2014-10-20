#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
#define MAXP 61
#define INF 1<<25
typedef long long ll;
int n, seq[101];
bool sv[MAXP];
int maskp[MAXP];

int dp[101][1 << 17];

int go(int idx, int mask) {
    if(idx >= n)return 0;
    int& ref = dp[idx][mask];
    if(ref == -1) {
        ref = INF;
        for(int i = 1; i < MAXP; ++i) {
            if((mask & maskp[i]) == 0  )
                ref = min(ref, go(idx + 1, mask | maskp[i]) + abs(seq[idx] - i));
        }
    }
    return ref;

}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)scanf("%d", &seq[i]);
    vector<int> primes;
    for(int i = 2; i * i < MAXP; ++i)
        if(sv[i] == 0)
            for(int j = i * i; j < MAXP; j = j + i)sv[j] = 1;

    for(int i = 2; i < MAXP; ++i)if(sv[i] == 0)primes.push_back(i);

    for(int i = 2; i < MAXP; ++i) {
        for(int j = 0; j < primes.size(); ++j)
            if(i % primes[j] == 0)maskp[i] |= 1 << j;
    }
    memset(dp, -1, sizeof dp);
    int ans = go(0, 0);
    int mask = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < MAXP; ++j) {
            if(mask & maskp[j])continue;
            if(ans == go(i + 1, mask | maskp[j]) + abs(seq[i] - j)) {
                printf("%d ", j);
                ans -= abs(seq[i] - j);
                mask |= maskp[j];
                break;
            }
        }
    }
    return 0;
}

