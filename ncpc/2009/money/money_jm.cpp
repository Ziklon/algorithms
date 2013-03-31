#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > edge;
vector<int> owe;
vector<bool> visited;

int dfs(int cur)
{
	if (visited[cur]) return 0;
	visited[cur] = true;
	int sum = owe[cur];
	for(int i=0;i<edge[cur].size();i++)
		sum += dfs(edge[cur][i]);
	return sum;
}

int main()
{
	int n, m;
	cin >> n >> m;
	edge.resize(n);
	owe.resize(n);
	visited.resize(n);
	for(int i=0;i<n;i++) cin >> owe[i];
	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i=0;i<n;i++) {
		if (visited[i]) continue;
		int t = dfs(i);
		if (t != 0) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	cout << "POSSIBLE" << endl;
	return 0;
}
