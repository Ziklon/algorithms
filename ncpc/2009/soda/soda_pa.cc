#include <cassert>
#include <cstdio>

int main(void) {
  int e, f, c;
  scanf("%d%d%d", &e, &f, &c);
  assert(0 <= e && e < 1000);
  assert(0 <= f && f < 1000);
  assert(0 <= c);
  e += f;
  int ans = 0;
  while (e >= c) {
    e -= c-1;
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
