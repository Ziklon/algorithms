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
#define MAX 10000
using namespace std;
int A[100][MAX];
int n,m;
string s;
void solve(){
	cin>>n>>m;
	REP(i,0,n){
		cin>>s;
		int pos=s.find("1");
		if(pos==-1){
			puts("-1");
			return;
		}
		int dis=0;
		REP(j,0,m){
			if(s[(j+pos)%m]=='1')
				dis=0;
			else
				dis++;
			A[i][(j+pos)%m]=dis;		
		}
		for(int j=m;j>0;j--){
			if(s[(j+pos)%m]=='1')
				dis=0;
			else
				dis++;
			A[i][(j+pos)%m]=min(dis,A[i][(j+pos)%m]);		
		}		
	}
	int res=INF;
	REP(i,0,m){
		int ans=0;
		REP(j,0,n)ans+=A[j][i];
		res=min(res,ans);
	}
	printf("%d\n",res);
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

