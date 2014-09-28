#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,a) for(int i=0;i<int(a);i++)
#define MAXN 100005
using namespace std;
typedef long long ll;
int n, seq[MAXN];

bool can[1 << 20];
int snext[20][MAXN];

int main() {
    scanf("%d", &n);

    REP(i, n)scanf("%d", seq + i);

    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < n; ++j) {
            if(j == 0)snext[i][j] = -1;
            else snext[i][j] = snext[i][j - 1];
            if(seq[j] & (1 << i))
                snext[i][j] = j;
        }
    }

    for(int last = 0; last < n; ++last) {
        int val = seq[last];
        int at = last;
        while(true) {
            can[val] = 1;
            if(at == 0)break;
            int closest = -1;
            for(int i = 0; i < 20; ++i)
                if((val & (1 << i)) == 0)
                    closest = max(closest, snext[i][at - 1]);

            at = closest;
            if(at < 0)break;
            val |= seq[at];
        }
    }
    int ans = 0;
    REP(i, 1 << 20)ans += can[i];
    printf("%d\n", ans);
    return 0;
}

