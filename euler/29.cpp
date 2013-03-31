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

vector<pair<int,int> > get(int n){
		vector<pair<int,int> > v;
		for(int i=2;i*i<=n;i++){
			int cnt=0;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			if(cnt)v.push_back(make_pair(i,cnt));
		}
		if(n>1)v.push_back(make_pair(n,1));
		return v;
}

void solve(){
	int ans=0;
	set<pair<vector<pair<int,int> >, int > > S;
	REP(i,2,101){
		REP(j,2,101){
			int g=0;
			vector<pair<int,int> >v=get(i);
			REP(k,0,v.sz)g=__gcd(g,v[k].second);			
			REP(k,0,v.sz)v[k].second/=g;
			S.insert(make_pair(v,g*j));
		}	
	}
	cout<<S.sz<<endl;
	
	
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

