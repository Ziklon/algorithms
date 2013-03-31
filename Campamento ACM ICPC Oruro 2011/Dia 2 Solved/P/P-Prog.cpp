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
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	int a, b, c, t;
	scanf("%d", &t);
	for(int cas=0; cas<t ;cas++){
		scanf("%d %d %d", &a, &b, &c);
		if(2*b-a == c)
			printf("%d\n", 2*c-b);
		else
			printf("%d\n", c*(b/a));
	}
}

