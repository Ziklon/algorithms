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
typedef long long LL;

int main(){
	//freopen("T.in", "r", stdin);
	//freopen("T.out", "w", stdout);
	int k, n;
	cin>>n;
	for(int i=0; i<n ;i++){
		vector<int> a(3);
		scanf("%d %d %d %d", &a[0], &a[1], &a[2], &k);
		vector<int> b(3, k/3);
		int aux = k%3;
		for(int i=0; i<3 ;i++){
			if(b[i] >= a[i]){
				aux += b[i] - a[i] + 1;
				b[i] = a[i]-1;
			}
		}
		bool flag = true;
		while(aux && flag){
			flag = false;
			for(int i=0; i<3 ;i++){
				if(b[i] < a[i]-1 && aux){
					flag = true;
					b[i]++;
					aux--;
				}
			}
		}
		LL r = 1LL;
		for(int i=0; i<3 ;i++)
			r *= LL(b[i]+1);
		cout<<r<<endl;
	}
}
