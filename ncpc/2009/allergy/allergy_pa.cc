#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int best[1<<20][7];
int k, D[50];

int Best(int left, int surpl) {
  if (!left) return 0;
  int &res = best[left][surpl];
  if (res == -1) {
    res = 1<<20;
    for (int i = 0; i < k; ++i)
      if (left & (1<<i)) {
	int neu = max(D[i], 1+surpl);
	res = min(res, neu-surpl + Best(left ^ (1<<i), neu-surpl-1));
      }
  }
  return res;
}

int main(void) {
  scanf("%d", &k);
  assert(1 <= k && k <= 20);
  for (int i = 0; i < k; ++i) {
    scanf("%d", D+i);
    assert(1 <= D[i] && D[i] <= 7);
  }
  memset(best, -1, sizeof(best));
  printf("%d\n", Best((1<<k)-1, 0));
  return 0;
}
