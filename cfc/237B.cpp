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
#define MAX 1<<20
using namespace std;
int n,a,b,k;

int M[55][55];
int P[55];

map<int,pair<int,int> >U;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&P[i]);
	int cur=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=P[i];j++){
			scanf("%d",&M[i][j]);
			U[cur]=make_pair(i,j);
			cur++;
		}
	cur=1;
	int sw=0;
	vector<string> res;	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=P[i];j++){
			if(M[i][j]!=cur){				
				pair<int,int> tmp=U[M[i][j]];				
				swap(M[i][j],M[tmp.first][tmp.second]);				
				stringstream ss;
				ss<<i<<" "<<j<<" "<<tmp.first<<" "<<tmp.second;
				res.push_back(ss.str());
				sw++;					
			}
			cur++;
		}
		

	cout<<sw<<endl;
	REP(i,0,sw)
		cout<<res[i]<<endl;
	
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

