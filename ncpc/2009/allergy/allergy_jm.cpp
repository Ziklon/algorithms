#include <iostream>

using namespace std;

int n, v[20];
int memo[1<<20][7];

int go(int left, int r)
{
	if (left==0) return r;
	int last = -1, &best = memo[left][r];
	if (best >= 0) return best;
	best = 999;
	for(int i=0;i<n;i++) {
		if (!((1<<i)&left)) continue;
		if (v[i] == last) continue;
		last = v[i];
		int b = max(0, r-v[i]+1);
		int br = b + v[i];		
		int w = (r+1) + go(left-(1<<i), br - (r+1));
		best = min(best, w);
	}
	return best;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> v[i];
	memset(memo,-1,sizeof(memo));
	sort(v,v+n);
	int ans = go((1<<n)-1, 0);
	cout << ans << endl;
	return 0;
}