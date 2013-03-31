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
	//freopen("I.in", "r", stdin);
	//freopen("I.out", "w", stdout);
	int n, count, x, type;
	while(scanf("%d", &n) == 1){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool fs = true, fq = true, fpq = true;
		for(int i=0; i<n ;i++){
			scanf("%d %d", &type, &x);
			if(type == 1){
				if(fs) s.push(x);
				if(fq) q.push(x);
				if(fpq) pq.push(x);
			}
			else{
				if(s.empty()) fs = false;
				if(q.empty()) fq = false;
				if(pq.empty()) fpq = false;
				if(fs){
					if(s.top() != x) fs = false;
					else s.pop();
				}
				if(fq){
					if(q.front() != x) fq = false;
					else q.pop();
				}
				if(fpq){
					if(pq.top() != x) fpq = false;
					else pq.pop();
				}
			}
		}
		if(fs + fq + fpq == 1){
			if(fs) printf("stack\n");
			if(fq) printf("queue\n");
			if(fpq) printf("priority queue\n");
		}
		else if(fs || fq || fpq) printf("not sure\n");
		else printf("impossible\n");
	}
}
