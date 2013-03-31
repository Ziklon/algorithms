#include <iostream>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

const int MAX = 7;

int cons1[MAX + 1][MAX + 1], cons2[MAX + 1][MAX + 1];
char solution[MAX][MAX+1];
int visited[MAX + 1][MAX + 1];
int n, cookie, recCalls;
bool solutionFound;

// Check for loops
bool dfs(int x, int y, int gx, int gy)
{
	if (visited[y][x] == cookie) return false;
	visited[y][x] = cookie;
	if (x == gx && y == gy) return true;

	if (y + 1 <= n && x + 1 <= n && solution[y][x] == '\\' && dfs(x + 1, y + 1, gx, gy))
		return true;
	if (y > 0 && x > 0 && solution[y-1][x-1]=='\\' && dfs(x-1, y-1, gx,gy))
		return true;
	if (y + 1 <= n && x > 0 && solution[y][x - 1] == '/' && dfs(x - 1, y + 1, gx, gy))
		return true;
	if (y > 0 && x + 1 <= n && solution[y - 1][x] == '/' && dfs(x + 1, y - 1, gx, gy))
		return true;
	return false;
}

bool putSlash(int x, int y)
{
	bool ok = true;
	ok &= --cons1[y + 1][x] >= 0;
	ok &= --cons1[y][x + 1] >= 0;
	ok &= --cons2[y][x] >= 0;
	ok &= --cons2[y + 1][x + 1] >= 0;

	cookie++;
	ok &= !dfs(x, y + 1, x + 1, y);
	
	solution[y][x] = '/';
	return ok;
}

void undoSlash(int x, int y)
{
	solution[y][x] = 0;
	++cons1[y + 1][x];
	++cons1[y][x + 1];
	++cons2[y][x];
	++cons2[y + 1][x + 1];
}

bool putBackSlash(int x, int y)
{
	bool ok = true;
	ok &= --cons2[y + 1][x] >= 0;
	ok &= --cons2[y][x + 1] >= 0;
	ok &= --cons1[y][x] >= 0;
	ok &= --cons1[y + 1][x + 1] >= 0;

	cookie++;
	ok &= !dfs(x, y, x + 1, y + 1);
	
	solution[y][x] = '\\';
	return ok;
}

void undoBackSlash(int x, int y)
{
	solution[y][x] = 0;
	++cons2[y + 1][x];
	++cons2[y][x + 1];
	++cons1[y][x];
	++cons1[y + 1][x + 1];
}

void rec(int i)
{
	recCalls++;
	if (i == n*n)
	{
		assert(!solutionFound);
		for (int i = 0; i < n; i++)
			cout << solution[i] << endl;
		solutionFound = true;
		return;
	}

	int sx = -1, sy = -1;

	// Find forced moves
	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			if (solution[y][x] == 0) {
				
				bool slash = putSlash(x,y);
				undoSlash(x, y);
				bool backSlash = putBackSlash(x,y);
				undoBackSlash(x, y);
				
				if (slash && !backSlash) {
					putSlash(x, y);
					rec(i+1);
					undoSlash(x,y);
					return;
				}
				
				if (!slash && backSlash) {
					putBackSlash(x, y);
					rec(i+1);
					undoBackSlash(x,y);
					return;
				}
				
				if (sx < 0) {
					sx = x;
					sy = y;
				}
			}
	
	if (putSlash(sx, sy)) rec(i + 1);
	undoSlash(sx, sy);

	if (putBackSlash(sx, sy)) rec(i + 1);
	undoBackSlash(sx, sy);
}

int main()
{
	memset(visited, 0, sizeof(visited));
	memset(solution, 0, sizeof(solution));
	
	solutionFound = false;
	cookie = 0;
	
	cin >> n;
	assert(n >= 2 && n <= MAX);	
	
	for (int i = 0; i < n + 1; i++)
	{
		char line[MAX+2];
		cin >> line;
		for (int j = 0; j < n + 1; j++)
		{
			char c = line[j];
			assert(c == '.' || (c >= '0' && c <= '4'));
			bool yEdge = i == 0 || i == n;
			bool xEdge = j == 0 || j == n;
			int tot = xEdge && yEdge ? 1 : (xEdge || yEdge ? 2 : 4);
			cons1[i][j] = c == '.' ? 4 : c - '0';
			cons2[i][j] = c == '.' ? 4 : (tot - (c - '0'));
			
			assert(cons1[i][j] >= 0 && cons2[i][j] >= 0);			
		}
	}
	
	recCalls = 0;
	rec(0);
	assert(solutionFound);
	//cerr << recCalls << " recursive calls" << endl;
	
	return 0;
}
