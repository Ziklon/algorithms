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
int n,k,x,res;
void solve(){
	scanf("%d %d",&n,&k);
	vector<pair<int,int> > v;
	REP(i,0,n){
		scanf("%d",&x);
		v.push_back(make_pair(x,i));
	}
	sort(all(v));
	reverse(all(v));
	printf("%d\n",v[k-1].first);
	REP(i,0,k){
		if(i)printf(" ");
		printf("%d",v[i].second+1);
	}
	printf("\n");
	
}
int main(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();	
	return 0;
}

