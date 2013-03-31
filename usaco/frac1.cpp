/*
ID: winftc2
PROG: frac1
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
#define oo 1<<30
using namespace std;

int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
bool orden(pair<int,int> p, pair<int,int>q){
	return p.first*q.second<p.second*q.first;
}

void solve(){
	int N,r,a,b;
	scanf("%d",&N);
	set<pair<int,int> >S;
	S.insert(make_pair(0,1));	
	for(int i=1;i<=N;i++){
		for(int j=N;j>=i;j--){
			r=gcd(i,j);
			a=i/r;
			b=j/r;
			S.insert(make_pair(a,b));
		}
	}
	vector<pair<int,int> >v(all(S));
	sort(all(v),orden);
	REP(i,0,v.sz){
		printf("%d/%d\n",v[i].first,v[i].second);
	}
	//printf("%d/%d ",v[i].first,v[i].second);
	
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	//freopen("frac1.in","r",stdin);
	//freopen("frac1.out","w",stdout);
	
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

