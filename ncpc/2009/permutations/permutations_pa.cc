#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
const ll MOD = (1LL<<31) - 1;

void factor(int n, vi &f) {
  for (int r = 2; r <= (n+r-1)/r; ++r)
    while (n % r == 0) f.push_back(r), n /= r;
  if (n > 1) f.push_back(n);
}

void divisor(const vi f, int i, int v, vi &d) {
  if (i == f.size()) d.push_back(v);
  else {
    int j;
    for (j = i; j < f.size() && f[j] == f[i]; ++j);
    for (int r = 0; r <= j-i; v *= f[i], ++r) divisor(f, j, v, d);
  }
}

vi facs, facps, divs;

ll mul(int l, int h) { 
  ll r = 1;
  for (int i = l; i <= h; ++i) r = (r*i) % MOD;
  return r;
}

ll ways[150][1<<10];
int N;
ll K;

int Cover(int d) {
  int r = 0;
  for (int i = 0; i < facps.size(); ++i)
    if (d % facps[i] == 0) r |= 1<<i;
  return r;
}

ll Ways(int n, int m) {
  if (!n) return m == 0;
  ll &res = ways[n][m];
  if (res == -1) {
    res = 0;
    for (vi::iterator it = divs.begin(); it != divs.end() && *it <= n; ++it)
      res = (res + mul(n-*it+1, n-1) * Ways(n-*it, m & ~Cover(*it))) % MOD;
  }
  return res;
}

int main(void) {
  scanf("%d%lld", &N, &K);
  
  assert(1 <= N && N <= 100);
  assert(1 <= K && K <= MOD);

  factor(K, facs);
  for (int i = 0, j, v; i < facs.size(); ) {
    for (v = 1, j = i; j < facs.size() && facs[j] == facs[i]; v *= facs[i], ++j);
    facps.push_back(v);
    i = j;
  }
  divisor(facs, 0, 1, divs);
  sort(divs.begin(), divs.end());

  //for (vi::iterator it = divs.begin(); it != divs.end(); ++it)    printf("  |%d\n", *it);
  //fprintf(stderr, "%d factors, %d distinct, %d divisors\n",  facs.size(), facps.size(), divs.size());

  memset(ways, -1, sizeof(ways));
  printf("%lld\n", Ways(N, (1<<facps.size())-1));

}
