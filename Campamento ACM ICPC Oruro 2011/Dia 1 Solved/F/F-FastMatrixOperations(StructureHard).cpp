#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

struct Treee{
	int mi, ma, inc, tot, se;
	Treee(){ inc = mi = ma = tot = se = 0; }
};
vector<vector<Treee> > T;
tree[40000];

struct IntTree{
	void op1(int x, int y1, int y2, int v, int ini = 1, int end = 5, int it = 1){
		int le = it*2, ri = le+1, mid = (ini+end)/2;
		if(T[x][it].se){
			if(ini == end){
				T[x][it].se += v;
				T[x][it].tot = T[x][it].se;
				T[x][it].mi = T[x][it].se;
				T[x][it].ma = T[x][it].se;
				return;
			}
			op2(x, ini, mid, T[x][it].se, ini, mid, le);
			op2(x, mid+1, end, T[x][it].se, mid+1, end, ri);
			T[x][it].se = 0;
		}
		if(ini == y1 && end == y2){
			T[x][it].inc += v;
			T[x][it].tot += v*(end-ini+1);
			T[x][it].mi += v;
			T[x][it].ma += v;
			return;
		}
		if(y2 <= mid)
			op1(x, y1, y2, v, ini, mid, le);
		else if(y1 > mid)
			op1(x, y1, y2, v, mid+1, end, ri);
		else {
			op1(x, y1, mid, v, ini, mid, le);
			op1(x, mid+1, y2, v, mid+1, end, ri);
		}
		T[x][it].mi = min(T[x][ri].mi, T[x][le].mi) + T[x][it].inc;
		T[x][it].ma = max(T[x][ri].ma, T[x][le].ma) + T[x][it].inc;
		T[x][it].tot = T[x][le].tot + T[x][ri].tot + T[x][it].inc*(end-ini+1);
	}
	
	void op2(int x, int y1, int y2, int v, int ini, int end, int it){
		int le = it<<1, ri = le+1, mid = (ini+end)>>1;
		if(ini == y1 && end == y2){
			T[x][it].se = v;
			T[x][it].inc = 0;
			T[x][it].tot = (end-ini+1)*v;
			T[x][it].mi = T[x][it].ma = v;
			return;
		}
		if(T[x][it].se){
			op2(x, ini, mid, T[x][it].se, ini, mid, le);
			op2(x, mid+1, end, T[x][it].se, mid+1, end, ri);
			T[x][it].se = 0;
		}
		if(T[x][it].inc){
			op1(x, ini, mid, T[x][it].inc, ini, mid, le);
			op1(x, mid+1, end, T[x][it].inc, mid+1, end, ri);
			T[x][it].inc = 0;
		}
		if(y2 <= mid)
			op2(x, y1, y2, v, ini, mid, le);
		else if(y1 > mid)
			op2(x, y1, y2, v, mid+1, end, ri);
		else {
			op2(x, y1, mid, v, ini, mid, le);
			op2(x, mid+1, y2, v, mid+1, end, ri);
		}
		T[x][it].mi = min(T[x][ri].mi, T[x][le].mi) + T[x][it].inc;
		T[x][it].ma = max(T[x][ri].ma, T[x][le].ma) + T[x][it].inc;
		T[x][it].tot = T[x][le].tot + T[x][ri].tot + T[x][it].inc*(end-ini+1);
	}
	
	vector<int> op3(int x, int y1, int y2, int ini, int end, int it){
		vector<int> r(3), r2;
		if(T[x][it].se){
			r[0] = T[x][it].se*(y2-y1+1), r[1] = T[x][it].se, r[2] = T[x][it].se;
			return r;
		}
		if(ini == y1 && end == y2){
			r[0] = T[x][it].tot, r[1] = T[x][it].mi, r[2] = T[x][it].ma;
			return r;
		}
		int le = it<<1, ri = le+1, mid = (ini+end)>>1;
		if(y2 <= mid)
			r = op3(x, y1, y2, ini, mid, le);
		else if(y1 > mid)
			r = op3(x, y1, y2, mid+1, end, ri);
		else {
			r = op3(x, y1, mid, ini, mid, le);
			r2 = op3(x, mid+1, y2, mid+1, end, ri);
			r[0] += r2[0], r[1] = min(r[1], r2[1]), r[2] = max(r[2], r2[2]);
		}
		r[0] += T[x][it].inc*(y2-y1+1);
		r[1] += T[x][it].inc;
		r[2] += T[x][it].inc;
		return r;
	}
	
};

int ro, co, m;

void solve1(){
	int op, x1, x2, y1, y2, v;
	T = vector<vector<Treee> > (ro+1, vector<Treee>((co+1)*4));
	IntTree tree;
	for(int i=0; i<m ;i++){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
			for(int x=x1; x<=x2 ;x++) tree.op1(x, y1, y2, v, 1, co, 1);
		}
		else if(op == 2){
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
			for(int x=x1; x<=x2 ;x++) tree.op2(x, y1, y2, v, 1, co, 1);
		}
		else{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			vector<int> r = tree.op3(x1, y1, y2, 1, co, 1), r2;
			for(int x=x1+1; x<=x2 ;x++){
				r2 = tree.op3(x, y1, y2, 1, co, 1);
				r[0] += r2[0], r[1] = min(r[1], r2[1]), r[2] = max(r[2], r2[2]);
			}
			printf("%d %d %d\n", r[0], r[1], r[2]);
		}
	}
}

void solve2(){
	int op, x1, x2, y1, y2, v;
	T = vector<vector<Treee> > (co+1, vector<Treee>((ro+1)*4));
	IntTree tree;
	for(int i=0; i<m ;i++){
		scanf("%d", &op);
		if(op == 1){
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
			for(int y=y1; y<=y2 ;y++) tree.op1(y, x1, x2, v, 1, ro, 1);
		}
		else if(op == 2){
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
			for(int y=y1; y<=y2 ;y++) tree.op2(y, x1, x2, v, 1, ro, 1);
		}
		else{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			vector<int> r = tree.op3(y1, x1, x2, 1, ro, 1), r2;
			for(int y=y1+1; y<=y2 ;y++){
				r2 = tree.op3(y, x1, x2, 1, ro, 1);
				r[0] += r2[0], r[1] = min(r[1], r2[1]), r[2] = max(r[2], r2[2]);
			}
			printf("%d %d %d\n", r[0], r[1], r[2]);
		}
	}
}

int main(){
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	while(scanf("%d %d %d", &ro, &co, &m) == 3){
		if(ro < co) solve1();
		else solve2();
	}
}

