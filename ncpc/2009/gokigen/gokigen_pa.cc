#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int value[15][15];
int open[15][15];
char cell[15][15];

const int bin[5][5] = {{1,0,0,0,0},
		       {1,1,0,0,0},
		       {1,2,1,0,0},
		       {1,3,3,1,0},
		       {1,4,6,4,1}};
const int dr[4] = {-1, -1, 0, 0};
const int dc[4] = {-1, 0, 0, -1};

inline bool cvalid(int ci, int cj) {
  return ci >= 0 && ci < n && cj >= 0 && cj < n;
}
    
inline bool cfree(int ci, int cj) { 
  return cvalid(ci, cj) && cell[ci][cj] == 0; 
}

inline bool valid(int i, int j) {
  return i >= 0 && i <= n && j >= 0 && j <= n; 
}

bool visited[15][15];

inline bool conn(int ai, int aj, int bi, int bj) {
  int dst = abs(ai-bi) + abs(aj-bj), dir = (ai-bi)*(aj-bj);
  int ans = cvalid(bi, bj) && cell[bi][bj] && 
    (dst == 1 && cell[bi][bj] != cell[ai][aj] ||
     dst == 2 && cell[bi][bj] == cell[ai][aj] && ((dir == 1) ^ (cell[ai][aj] == '/')));
  return ans;
}

void dfs(int ci, int cj, int pi, int pj) {
  visited[ci][cj] = true;
  for (int ni = ci-1; ni <= ci+1; ++ni)
    for (int nj = cj-1; nj <= cj+1; ++nj)
      if (conn(ci, cj, ni, nj) && (pi != ni || pj != nj))
	if (!visited[ni][nj]) dfs(ni, nj, ci, cj);
}

bool loop(int ci, int cj, char val) {
  memset(visited, 0, sizeof(visited));
  visited[ci][cj] = true;
  bool res = false;
  cell[ci][cj] = val;
  for (int i = ci-1; i <= ci; ++i)
    for (int dj = -1; dj < 1; ++dj) {
      int j = cj + dj + (val == '/');
      if (conn(ci, cj, i, j)) dfs(i, j, ci, cj);
    }
  for (int i = ci; i <= ci+1; ++i) {
    for (int dj = -1; dj < 1; ++dj) {
      int j = cj + dj + (val == '\\');
      if (conn(ci, cj, i, j) && visited[i][j]) res = true;
    }
  }
  cell[ci][cj] = 0;
  return res;
}

bool solve() {
  int bp = 1000, bi = -1, bj = -1;
  for (int i = 0; i <= n; ++i)
    for( int j = 0; j <= n; ++j) {
      if (!open[i][j]) continue;
      int p = value[i][j] >= 0 ? bin[open[i][j]][value[i][j]] : 1<<open[i][j];
      if (p < bp)
	bi = i, bj = j, bp = p;
    }
  if (bi == -1) return true;
  
  int ci, cj, dir;
  for (dir = 0; dir < 4; ++dir)
    if (cfree(ci = bi + dr[dir], cj = bj + dc[dir]))
      break;

  for (int x = 0; x < 2; ++x) {
    if (value[bi][bj] >= 0 && 
	(x > value[bi][bj] || value[bi][bj]-x > open[bi][bj]-1)) continue;
    char val = (x ^ dir % 2) ? '\\' : '/';
    if (loop(ci, cj, val)) continue;
    cell[ci][cj] = val;
    bool ok = true;
    for (int d = 0; d < 4; ++d) {
      int i = ci - dr[d], j = cj - dc[d];
      if (valid(i, j)) {
	--open[i][j];
	if (value[i][j] >= 0) {
	  value[i][j] -= x ^ (dir + d) % 2;
	  if (value[i][j] < 0) ok = false;
	}
	if (value[i][j] > open[i][j]) ok = false;
      }
    }
    if (ok && solve()) return true;
    cell[ci][cj] = 0;
    for (int d = 0; d < 4; ++d) {
      int i = ci - dr[d], j = cj - dc[d];
      if (valid(i, j)) {
	++open[i][j];
	if (value[i][j] >= -1)
	  value[i][j] += x ^ (dir + d) % 2;
      }
    }
  }
  return false;
}

int main(void) {

  scanf("%d", &n);
  
  assert(2 <= n && n <= 7);

  for (int i = 0; i <= n; ++i) {
    char row[100];
    scanf("%s", row);
    assert(strlen(row) == n+1);
    for (int j = 0; j <= n; ++j) {
      assert(row[j] == '.' || (row[j] >= '0' && row[j] <= '4'));
      open[i][j] = 4;
      value[i][j] = row[j] == '.' ? -10 : row[j]-'0';
    }
  }
  for (int i = 0; i <= n; ++i)
    open[0][i] = open[i][0] = open[i][n] = open[n][i] = 2;
  open[0][0] = open[0][n] = open[n][0] = open[n][n] = 1;

  assert(solve());

  for (int i = 0; i < n; ++i) {
    cell[i][n] = 0;
    printf("%s\n", cell[i]);
  }
  return 0;
}
