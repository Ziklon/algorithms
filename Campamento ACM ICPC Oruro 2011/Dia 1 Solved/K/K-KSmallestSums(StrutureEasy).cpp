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

int main(){
	//freopen("K.in", "r", stdin);
	//freopen("K.out", "w", stdout);
	int k, x, y;
	while(scanf("%d", &k) == 1){
		vector<vector<int> > v(k, vector<int>(k));
		multiset<int> best;
		multiset<int>::reverse_iterator it;
		int sum = 0;
		best.insert(0);
		for(int i=0; i<k ;i++){
			for(int j=0; j<k ;j++) scanf("%d", &v[i][j]);
			sort(v[i].begin(), v[i].end());
			if(i){
				vector<int> vaux;
				for(int j=1; j<k ;j++){
					x = v[i][0] - v[i][j];
					y = (*best.begin());
					for(it=best.rbegin(); it!=best.rend() ;it++){
						if(x + (*it) < y) break;
						vaux.push_back(x + (*it));
					}
				}
				best.insert(vaux.begin(), vaux.end());
			}
			else{
				for(int j=1; j<k ;j++){
					x = v[i][0] - v[i][j];
					best.insert(x);
				}
			}
			while(best.size() > k) best.erase(best.begin());
			sum += v[i][0];
		}
		it = best.rbegin();
		for(int i=0; i<k ;i++){
			if(i) printf(" ");
			printf("%d", sum - (*it));
			it++;
		}
		printf("\n");
	}
}
