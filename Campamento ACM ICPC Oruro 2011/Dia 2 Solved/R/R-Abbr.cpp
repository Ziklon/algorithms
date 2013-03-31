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
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	int t, n;
	scanf("%d", &t);
	string s, vs[] = {"UCC", "UUU", "UCU", "CUC", "UCB"};
	for(int cas=0; cas<t ;cas++){
		int v[5] = {0}, w[5] = {0};
		cin>>s;
		for(int i=0; i<s.size()-2 ;i++){
			for(int j=0; j<5 ;j++){
				bool ok=true;
				for(int k=0; k<3 ;k++)
					if(s[i+k] != vs[j][k])
						ok = false;
				if(ok) w[j]++;
			}
			if(s[i] == 'U'){
				if(s[i+1] == 'C'){
					if(s[i+2] == 'C') v[0]++;
					if(s[i+2] == 'U') v[2]++;
					if(s[i+2] == 'B') v[4]++;
				}
				if(s[i+1] == 'U')
					if(s[i+2] == 'U') v[1]++;
			}
			if(s[i] == 'C')
				if(s[i+1] == 'U')
					if(s[i+2] == 'C') v[3]++;
		}
		for(int i=0; i<5 ;i++){
			if(i) printf(" ");
			if(w[i] != v[i]) printf("error\n");
			printf("%d", v[i]);
		}
		printf("\n");
	}
}

