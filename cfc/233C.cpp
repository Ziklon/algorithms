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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
ll n,x,tmp;
vector<string> v;
void solve(){
	cin>>n;
	x=3;
	for(;;x++){
		tmp=(x)*(x-1)*(x-2);
		if(tmp/6>=n)
			break;
	}
	for(int i=0;i<x;i++)v.push_back(string(x,'0'));
	int cycle=0;
	cout<<v.sz<<endl;
	for(int i=0;i<x;i++)for(int j=i+1;j<x;j++)for(int k=j+1;k<x;k++){
		if(cycle<n){
			v[i][j]='1';
			v[j][k]='1';
			v[k][i]='1';
			cycle++;
		}
	}
	/*
	for(int i=0;i<x;i++)for(int j=0;j<x;j++)if(v[i][j]=='1'){
		v[j][i]='1';
	}
	*/
	for(int i=0;i<x;i++)cout<<v[i]<<endl;
	
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

