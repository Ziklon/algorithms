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
char cad;
void solve(){
	int m,n;
	vector<pair<int,int> >v;
	scanf("%d %d\n",&n,&m);
	REP(i,0,n){
		REP(j,0,m){
			scanf("%c",&cad);
			if(cad=='*'){
				v.push_back(make_pair(i+1,j+1));
			}
		}
		scanf("\n");
	
	}
	map<int,int>R;
	map<int,int>S;
	REP(i,0,v.sz){
		//cout<<v[i].first<<" "<<v[i].second<<endl;
		R[v[i].first]++;
		S[v[i].second]++;
	}
	vector<int> ans;
	foreach(R,it){
		if(it->second%2==1)
			ans.push_back(it->first);	
	}
	foreach(S,it){
		if(it->second%2==1)
			ans.push_back(it->first);
	
	}
	cout<<ans[0]<<" "<<ans[1]<<endl; 
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

