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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int n;
string s;
void solve(){
	scanf("%d\n",&n);
	REP(i,0,n){
		getline(cin,s);
		vector<int> v(26,0);
		REP(j,0,s.sz){
			if(isalpha(s[j]))
				v[tolower(s[j])-'a']++;
		}
		int mx=0;
		REP(j,0,26)mx=max(mx,v[j]);
		
		s="";
		REP(j,0,26)if(mx==v[j])s+=string(1,'a'+j);
		
		printf("%s\n",s.c_str());
		
	}
	
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

