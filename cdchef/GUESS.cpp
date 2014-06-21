#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005
int T, N, M;

ll odds(int n){
    return ((n-1)>>1)+1;
}
ll evens(int n){
    return n>>1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d %d", &N, &M);
        ll uv = (odds(N)*evens(M)) + ((evens(N)*odds(M)));
        ll tt = (N*1LL)*M;
        ll gg = __gcd(uv,tt);
        uv/=gg;
        tt/=gg;        
        printf("%lld/%lld\n",uv,tt);
    }
    return 0;
}
