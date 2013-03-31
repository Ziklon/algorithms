/*
ID: winftc2
PROG: sort3
LANG: C++
 */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define oo 1<<30

using namespace std;


void solve(){
	int n; scanf ("%d", &n);
	int a [1000 + 10];
	int freq [3 + 2]; fill (freq, 0);

	for ( int i = 0; i < n; i++ ) {
		scanf ("%d", &a [i]);
		freq [a [i]]++;
	}

	int groupFreq [3 + 2] [3 + 2]; fill (groupFreq, 0);
	int len = 0;

	for ( int i = 1; i <= 3; i++ ) {
		for ( int j = 0; j < freq [i]; j++ ) {
			groupFreq [i] [a [len]]++;
			len++;
		}
	}

	int cnt = 0;
	int mini;

	mini = min (groupFreq [1] [2], groupFreq [2] [1]);
	groupFreq [1] [2] -= mini;
	groupFreq [2] [1] -= mini;
	groupFreq [1] [1] += mini;
	groupFreq [2] [2] += mini;
	cnt += mini;

	mini = min (groupFreq [1] [3], groupFreq [3] [1]);
	groupFreq [1] [3] -= mini;
	groupFreq [3] [1] -= mini;
	groupFreq [1] [1] += mini;
	groupFreq [3] [3] += mini;
	cnt += mini;

	mini = freq [1] - groupFreq [1] [1];
	cnt += mini;
	groupFreq [1] [1] = freq [1];
	groupFreq [2] [1] = groupFreq [3] [1] = 0;
	groupFreq [3] [2] += groupFreq [1] [2];
	groupFreq [2] [3] += groupFreq [1] [3];
	groupFreq [1] [2] = groupFreq [1] [3] = 0;
	cnt += groupFreq [2] [3];

	printf ("%d\n", cnt);
	
}
int main(){
	#ifdef LocalHost
		//freopen("D:/input.txt","r",stdin);
		//clock_t start = clock();
	#endif
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

