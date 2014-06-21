#include <bits/stdc++.h>
using namespace std;
#define MAXN 1<<20
int T, N, len;

char s[MAXN], x, y;
char c[300];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d\n", &T);
    for(int t = 1; t <= T; ++t) {

        scanf("%d\n", &N);
        for(int i = 0; i < 256; ++i)c[i] = i;
        for(int i = 0; i < N; ++i) {
            scanf("%c %c\n", &x, &y);
            c[x] = y;
        }

        scanf("%s\n", s);
        len = strlen(s);
        bool hasPoint = false;
        for(int i = 0; i < len; ++i) {
            s[i]=c[s[i]];
            if(s[i] == '.')hasPoint = 1;
        }
        int from = 0, to = len - 1;
        while(s[from] == '0' && from < len)++from;

        if(hasPoint) {
            while((s[to] == '0')  && to >= 0)--to;
            if(to >= 0 && s[to] == '.')--to;
        }
        if(to < from)printf("0\n");
        else {
            for(int i = from; i <= to; ++i)printf("%c", s[i]);
            printf("\n");
        }
    }
    return 0;
}
