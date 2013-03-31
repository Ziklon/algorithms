#include <cassert>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

const double inf = 1e50;

int n, m, e;
vpii adj[200];
bool exit[200];


void dijkstra(int src, double speed, double *ans, double *death) {
  bool used[200];
  for (int i = 0; i < n; ++i) ans[i] = inf, used[i] = false;
  ans[src] = 0;
  for (int i = 0; i < n; ++i) {
    int a = -1;
    for (int b = 0; b < n; ++b)
      if (!used[b] && (a == -1 || ans[b] < ans[a]))
    a = b;
    if (ans[a] == inf) break;
    used[a] = true;
    for (vpii::iterator it = adj[a].begin(); it != adj[a].end(); ++it) {
      double nt = ans[a] + 0.1*it->second / speed;
      if (nt < death[it->first])
    ans[it->first] = min(ans[it->first], nt);
    }
  }
}

double police[200];

bool cando(int src, double speed) {
  double t[200];
  dijkstra(src, speed, t, police);
  for (int i = 0; i < n; ++i)
    if (t[i] < inf && exit[i]) return true;
  return false;
}

int main(void) {
  scanf("%d%d%d", &n, &m, &e);
  assert(2 <= n && n <= 100);
  assert(1 <= m && m <= 5000);
  for (int i = 0; i < m; ++i) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    assert(1 <= a && a <= n);
    assert(1 <= a && a < b && b <= n);
    assert(1 <= l && l <= 100);
    --a; --b;
    adj[a].push_back(pii(b, l));
    adj[b].push_back(pii(a, l));
  }
  memset(exit, 0, sizeof(exit));
  for (int i = 0; i < e; ++i) {
    int E;
    scanf("%d", &E);
    assert(1 <= E && E <= n);
    --E;
    exit[E] = true;
  }

  int b, p;
  scanf("%d%d", &b, &p);
  assert(1 <= b && b <= n);
  assert(1 <= p && b != p && p <= n);
  --b;
  --p;

  dijkstra(p, 160, police, police);

  double lo = 0, hi = 1e8;
  
  for (int i = 0; i < 100; ++i) {
    double m = (lo+hi)/2;
    if (cando(b, m)) hi = m;
    else lo = m;
  }

  if (hi == 1e8) printf("IMPOSSIBLE\n");
  else printf("%.9lf\n", hi);

}
