/*
  Sample solution for NCPC 2009: Money Matters
  Author: Marcus Isaksson
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<bool> Vb;

int n,m;
Mi friends; // friends[i] contains a list of friends of i
Vi owes; // Person i owes owes[i] in total
Vb vis;

int dfs(int i) {
  if (vis[i]) return 0;
  vis[i]=true;
  int sum=owes[i];
  for (int j=0; j<friends[i].size(); j++)
    sum+=dfs(friends[i][j]);
  return sum;
}

int main() {
  cin >> n >> m;
  owes=Vi(n);
  friends=Mi(n);
  for (int i=0; i<n; i++)
    cin >> owes[i];
  for (int i=0; i<m; i++) {
    int a,b;
    cin >> a >> b;
    friends[a].push_back(b);
    friends[b].push_back(a);
  }

  vis=Vb(n);
  for (int i=0; i<n; i++)
    if (!vis[i] && dfs(i)!=0) {
      cout << "IM";
      break;
    }

  cout << "POSSIBLE\n";
  return 0;
}
