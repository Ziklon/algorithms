#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 999999;

int dist[100][100];
double policeTime[100];
bool isExit[100];

int main()
{
	for(int i=0;i<100;i++) policeTime[i] = -1.0;
	memset(dist,-1,sizeof(dist));
	memset(isExit,0,sizeof(isExit));

	int n, m, e, a, b, l, p;
	cin >> n >> m >> e;
	for(int i=0;i<n;i++) dist[i][i]=0;
	for(int i=0;i<m;i++) {
		cin >> a >> b >> l;
		a--; b--;
		dist[a][b] = dist[b][a] = l;
	}
	
	for(int i=0;i<e;i++) {
		cin >> a;
		isExit[a-1] = true;
	}
	
	cin >> b >> p;
	b--;
	p--;
	
	policeTime[p] = 0;
	vector<bool> done(n);
	for(int i=0;i<n;i++) {
		int select = -1;
		double best = INF;
		for(int j=0;j<n;j++)
			if (!done[j] && policeTime[j] >= 0 && policeTime[j] < best) {
				best = policeTime[j];
				select = j;
			}
		done[select] = true;
		for(int j=0;j<n;j++)
			if (dist[select][j] >= 0) {
				double pt = best + dist[select][j]/16.0;
				if (policeTime[j] < 0 || pt < policeTime[j])
					policeTime[j] = pt;
			}
	}
	
	double lo = 0, hi = INF;
	double time[100];

	while (hi-lo > 1e-8) {
		double speed = (hi+lo) / 2;
		for(int i=0;i<n;i++) {
			time[i] = -1.0;
			done[i] = false;
		}
		time[b] = 0;
		bool canReachExit = false;
		while (!canReachExit) {
			int select = -1;
			double best = INF;
			for(int j=0;j<n;j++)
				if (!done[j] && time[j] >= 0 && time[j] < best && time[j] < policeTime[j]) {
					best = time[j];
					select = j;
				}
			if (select < 0) break;
			done[select] = true;
			if (isExit[select]) canReachExit = true;
			for(int j=0;j<n;j++)
				if (dist[select][j] >= 0) {
					double bt = best + dist[select][j]/speed;
					if (time[j] < 0 || bt < time[j])
						time[j] = bt;
				}
		}
		if (canReachExit)
			hi = speed;
		else
			lo = speed;		
	}
	if (hi > INF-1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << fixed << setprecision(9) << lo * 10.0 << endl;
		
	return 0;
}
