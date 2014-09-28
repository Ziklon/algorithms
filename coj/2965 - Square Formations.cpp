#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T, K, N;


bool isSquare(int n) {
    int d = (int)(sqrt(n) + 0.5);
    return d * d == n;
}


int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);



    for(int t = 1; t <= T; ++t) {
        scanf("%d", &K);
        N = 1 << 30;

        for(int i = 1; i <= 1000; ++i) {
            int sq = (i * i);
            int tmp = sq - K;
            if(tmp >= 1 && isSquare((tmp / 2) + K)) N = min(tmp, N);

        }
        printf("Case %d: %d\n", t, N);

    }
    return 0;
}
