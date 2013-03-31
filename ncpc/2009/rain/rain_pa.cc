#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;

double L, K, T1, T2, H;

double check(double R) {
  return R < L ? R : K*T1 > R ? L : max(L, R - K*(T2+T1*(1-L/R)));
}

double search(double v) {
  double lo = 0, hi = 1e10, m;
  for (int i = 0; i < 100; ++i) (check(m =(lo+hi)/2) > H + v ? hi : lo) = m;
  return lo;
}

int main(void) {
  scanf("%lf%lf%lf%lf%lf", &L, &K, &T1, &T2, &H);
  assert(0.01 <= L && L <= 1000);
  assert(0.01 <= K && K <= 1000);
  assert(0.01 <= T1 && T1 <= 1000);
  assert(0.01 <= T2 && T2 <= 1000);
  assert(0.01 <= H && H <= 1000);
  printf("%.9lf %.9lf\n", search(-1e-11), search(1e-11));
  return 0;
}
