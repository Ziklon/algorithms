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
int n;
string cad;


void solve(){
	cin>>n;
    cin>>cad;
    vector<int> a,b;
	REP(i,0,n){
		a.push_back(cad[i]-'0');
		b.push_back(cad[i+n]-'0');
	}
	sort(all(a));
	sort(all(b));
	bool ok1=0;
	bool ok2=0;
	REP(i,0,n){
		ok1|=(a[i]<=b[i]);
		ok2|=(a[i]>=b[i]);
	}
	if(!ok1 || !ok2)puts("YES");
	else puts("NO");
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

