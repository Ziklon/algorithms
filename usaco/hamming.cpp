/*
ID: winftc2
PROG: hamming
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
#define INF 1<<30
using namespace std;
int N,B,D;
int dis[260][260];
vector<int> ans;
void setdis(int a, int b){

	int dif=0;
	REP(i,0,8){
		if((a&(1<<i))^(b&(1<<i)))dif++;	
	}
	dis[a][b]=dif;
	dis[b][a]=dif;

}
bool check(int n){
	REP(i,0,ans.sz)if(dis[ans[i]][n]<D)return 0;
	return 1;
}
void solve(){
	
	REP(i,0,256)REP(j,i,256)setdis(i,j);
	
	cin>>N>>B>>D;
	ans.clear();
	
	ans.push_back(0);
	int num=1;
	

	 while(ans.sz<N){			
		while(!check(num))num++;		
		 ans.push_back(num);				
	 }

	REP(i,0,ans.sz){
		if(i%10!=0)printf(" ");
		printf("%d",ans[i]);
		if((i+1)%10==0)printf("\n");
	}
	if(ans.sz%10!=0)printf("\n");
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	
	#else
		freopen("hamming.in","r",stdin);
		freopen("hamming.out","w",stdout);
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

