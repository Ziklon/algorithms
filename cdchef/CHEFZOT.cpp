#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int N, x;
int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    int last = 0;
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &x);
        if(x == 0) {
            ans = max(ans,(i - (last + 1)));
            last = i;
        }
    }
    if(last == 0)ans = N;
    printf("%d\n", ans);
    return 0;
}
