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

int p[100001];
int sets[100001], rank[100001], sum[100001];

void make_set(int x){
	p[x] = sum[x] = sets[x] = x;
	rank[x] = 1;
}

int find_set(int x){
	if(x != sets[x]) sets[x] = find_set(sets[x]);
	return sets[x];
}

void link(int x, int y){
	if(rank[x] > rank[y]){
		sum[x] += sum[y];
		rank[x] += rank[y];
		sets[y] = x;
	}
	else{
		sum[y] += sum[x];
		rank[y] += rank[x];
		sets[x] = y;
	}
}



int main(){
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	int n, m, a, b, c, x, y;
	while(scanf("%d %d", &n, &m) == 2){
		for(int i=1; i<=n ;i++) make_set(i);
		F(i, m){
			scanf("%d %d", &a, &b);
			if(a == 1){
				scanf("%d", &c);
				p[b] = find_set(p[b]);
				p[c] = find_set(p[c]);
				if(p[b] != p[c]){
					link(p[b], p[c]);
					p[b] = find_set(p[b]);
					p[c] = find_set(p[c]);
				}
			}
			else if(a == 2){
				scanf("%d", &c);
				p[b] = find_set(p[b]);
				p[c] = find_set(p[c]);
				if(p[b] != p[c]){
					sum[ p[b] ] -= b;
					rank[ p[b] ]--;
					p[b] = p[c];
					sum[ p[b] ] += b;
					rank[ p[b] ]++;
				}
			}
			else{
				p[b] = find_set(p[b]);
				x = rank[ p[b] ];
				y = sum[ p[b] ];
				printf("%d %d\n", x, y);
			}
		}
	}
}

