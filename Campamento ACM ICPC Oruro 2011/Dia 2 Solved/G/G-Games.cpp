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
#define MP			make_pair
#define S           size()
typedef long long	LL;

int main(){
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	int n, m, x, k, aux, tt;
	scanf("%d", &tt);
	F(i, tt){
		scanf("%d %d", &n, &m);
		pair<LL, LL> oki(0LL, 0LL);
		vector<pair<LL,LL> > v(n+1, oki);
		F(i, m){
			scanf("%d %d", &x, &k);
			F(j, k){
				scanf("%d", &aux);
				aux--;
				if(aux >= 50) v[x].second |= (1LL<<(aux-50));
				else v[x].first |= (1LL<<aux);
			}
		}
		set<int> fal;
		vector<int> res;
		FOR(i, 1, n+1) fal.insert(i);
		while(!fal.empty()){
			for(set<int>::iterator it=fal.begin(); it!=fal.end() ;it++)
				if((oki.first & v[*it].first) == v[*it].first)
				if((oki.second & v[*it].second) == v[*it].second){
					aux = *it;
					break;
				}
			fal.erase(aux);
			res.PB(aux);
			aux--;
			if(aux >= 50) oki.second |= (1LL<<(aux-50));
			else oki.first |= (1LL<<aux);
		}
		F(i, res.S){
			if(i) printf(" ");
			printf("%d", res[i]);
		}
		printf("\n");
	}
}

