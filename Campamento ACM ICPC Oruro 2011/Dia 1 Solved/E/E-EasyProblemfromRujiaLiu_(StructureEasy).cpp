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

vector<vector<int> > array;

struct E{
	E(){
		array = vector<vector<int> > (1000001);
	}
	void insert(int x, int it){
		array[x].push_back(it);
	}
	void print(int k, int v){
		if(array[v].size() <= k) printf("0\n");
		else printf("%d\n", array[v][k]);
	}
};

int main(){
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	int n, m, x, k, v;
	while(scanf("%d %d", &n, &m) == 2){
		E e;
		for(int i=0; i<n ;i++){
			scanf("%d", &x);
			e.insert(x, i+1);
		}
		for(int i=0; i<m ;i++){
			scanf("%d %d", &k, &v);
			e.print(k-1, v);
		}
	}
}
