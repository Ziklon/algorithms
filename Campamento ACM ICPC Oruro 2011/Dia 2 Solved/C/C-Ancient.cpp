#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<queue>
using namespace std;
#define FOR(i,a,b)	for(int i=(a),_##i=(b); i<_##i ;i++)
#define F(i,n)		FOR(i,0,n)
#define ALL(v)		v.begin(),v.end()
#define S		size()
#define PB		push_back
#define MP		make_pair
typedef long long	LL;
vector<vector<bool> > v;
int n, m, fig[210][210];
int wmax, wmin;
int hmax, hmin;

void bfs2(int x, int y){
	queue<pair<int,int> > q;
	q.push(MP(x, y));
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(x < hmin-1 || y < wmin-1) continue;
		if(x > hmax+1 || y > wmax+1) continue;
		if(!fig[x][y]){
			fig[x][y] = 1;
			q.push(MP(x+1, y));
			q.push(MP(x-1, y));
			q.push(MP(x, y+1));
			q.push(MP(x, y-1));
		}
	}
}

string sol;
void bfs(int x, int y){
	memset(fig, 0, sizeof(fig));
	queue<pair<int,int> > q;
	q.push(MP(x, y));
	wmax = y, wmin = y;
	hmax = x, hmin = x;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if(x < 0 || y < 0) continue;
		if(x >= n || y >= m) continue;
		if(v[x][y]){
			if(fig[x][y]) continue;
			hmax = max(hmax, x);
			hmin = min(hmin, x);
			wmax = max(wmax, y);
			wmin = min(wmin, y);
			fig[x][y] = 1;
			v[x][y] = 0;
			q.push(MP(x+1, y));
			q.push(MP(x-1, y));
			q.push(MP(x, y+1));
			q.push(MP(x, y-1));
		}
	}
	int r = 0;
	FOR(i, hmin-1, hmax+1){
		FOR(j, wmin-1, wmax+1){
			if(fig[i][j] == false){
				bfs2(i, j);
				r++;
			}
		}
	}
	if(r == 1) sol.PB('W');
	else if(r == 2) sol.PB('A');
	else if(r == 3) sol.PB('K');
	else if(r == 4) sol.PB('J');
	else if(r == 5) sol.PB('S');
	else sol.PB('D');
}

void cortar(){
	sol.clear();
	F(i, n) F(j, m){
		if(v[i][j]){
			bfs(i, j);
		}
	}
	sort(ALL(sol));
	cout<<sol<<endl;
}

int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	string s;
	int cas = 1;
	scanf("%d %d", &n, &m);
	while(n){
		printf("Case %d: ", cas++);
		v = vector<vector<bool> >(n+2, vector<bool> (m*4 + 2, 0));
		F(i, n){
			cin>>s;
			F(j, s.S){
				int aux = 0;
				if(s[j] != '0'){
					if(s[j] >= 'a' && s[j] <= 'f')
						aux = s[j]-'a'+10;
					else
						aux = s[j]-'0';
				}
				F(k, 4)
					if(aux&(1<<k)) v[i + 1][j*4+(3-k) + 1] = 1;
			}
		}
		n = n + 2;
		m = m*4 + 2;
		cortar();
		scanf("%d %d", &n, &m);
	}
}

