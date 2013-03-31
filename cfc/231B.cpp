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
int N,L,W;
int dp[102][10001][2];

int go(int index, int num, int pos){	
	if(index==N-1){
		if(pos && num<=L){
			W=num;
			return 1;
		}
		return 0;
	}
	int& ref=dp[index][num][pos];	
	if(ref!=-1)return ref;
	ref=0;	
	if(pos==0)num*=-1;	
	REP(i,1,L+1){
		int j=i-num;
		ref=max(ref,go(index+1,abs(j),j>0));	
	}
	return ref;
}


void solve(){
	int d,res;
	cin>>N>>d>>L;
	fill(dp,-1);
	res=go(0,abs(d),d>0);
	if(!res){
		puts("-1");
		return;
	}
	vector<int> v(1,W);
	
	for(int i=N-2;i>=0;i--){
		
		
		for(int j=1;j<=L;j++){
			 		
		
		}
	
	
	}
	
	REP(i,0,v.sz){
		if(i==v.sz-1)cout<<v[i]<<endl;
		else
		cout<<v[i]<<" ";
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

