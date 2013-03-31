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
typedef pair<int,int> pii;
int a,b;
pair<int,pair<int,int> > egcd(int a, int b){
	if(b==0)return make_pair(a,make_pair(1,0));
	pair<int,pii> ans=egcd(b,a%b);
	return make_pair(ans.first,make_pair(ans.second.second,ans.second.first-ans.second.second*(a/b)));
}
void inv(int a,int b){
	pair<int,pii > ans=egcd(a,b);
	printf("%d %d %d\n",ans.second.first,ans.second.second,ans.first);	
}
void solve(){
	
	while(scanf("%d %d",&a,&b)==2){
		inv(a,b);
	
	}
	
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

