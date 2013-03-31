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

vector<pair<int,int> > v;
int n;

bool oki(int x){
	int act = v[0].first + x;
	for(int i=1; i<n ;i++){
		if(act > v[i].second) return false;
		if(act < v[i].first) act = v[i].first;
		act += x;
	}
	return true;
}

int binaryS(){
	if(oki(1) == false) return 0;
	int a = 0, b = v[1].second-v[0].first;
	while(a < b){
		int mid = ((a+b)/2) + 1;
		if(oki(mid)) a = mid;
		else b = mid-1;
	}
	return a;
}

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int cas = 1;
	while(scanf("%d", &n) && n){
		v.resize(n);
		F(i, n){
			scanf("%d %d", &v[i].first, &v[i].second);
			v[i].first *= 600;
			v[i].second *= 600;
		}
		int r = 0;
		sort(ALL(v));
		do{
			r = max(r, binaryS());
		}while(next_permutation(ALL(v)));
		r = (r+5)/10;
		if((r%60) < 10) printf("Case %d: %d:0%d\n", cas++, r/60, r%60);
		else printf("Case %d: %d:%d\n", cas++, r/60, r%60);
	}
}

