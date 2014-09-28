#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define REP(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 3)puts("NO");
    else
        if(n & 1) {
            puts("YES");
            printf("%d - %d = %d\n", 3, 1, 2);
            printf("%d + %d = %d\n", 2, 2, 4);
            printf("%d * %d = %d\n", 5, 4, 20);
            printf("%d + %d = %d\n", 20, 4, 24);
            for(int i = 6; i < n; i += 2) {
                printf("%d - %d = %d\n", i + 1, i, 1);
                printf("%d * %d = %d\n", 24, 1, 24);
            }
        } else {
            puts("YES");
            printf("%d * %d = %d\n", 1, 2, 2);
            printf("%d * %d = %d\n", 3, 4, 12);
            printf("%d * %d = %d\n", 12, 2, 24);
            for(int i = 5; i < n; i += 2) {
                printf("%d - %d = %d\n", i + 1, i, 1);
                printf("%d * %d = %d\n", 24, 1, 24);
            }
        }
    return 0;
}

