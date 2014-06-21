#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
char s[MAXN];

int dist[MAXN], len;

vector<int> G[10];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%s\n", s);
    len = strlen(s);

    for(int i = 0; i < len; ++i) {
        G[s[i] - '0'].push_back(i);
        dist[i] = -1;
    }    
    queue<int> Q;
    Q.push(0);
    dist[0] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if(cur - 1 >= 0 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            Q.push(cur - 1);
        }
        if(cur + 1 < len && dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1;
            Q.push(cur + 1);
        }
        int val = s[cur]-'0';        
        while(!G[val].empty()) {
            int to = G[val].back();
            G[val].pop_back();
            if(dist[to] == -1) {
                Q.push(to);
                dist[to] = dist[cur] + 1;
            }
        }
    }
    printf("%d\n", dist[len - 1]);
    return 0;
}
