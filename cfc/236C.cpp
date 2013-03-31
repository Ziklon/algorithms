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
#define MAX 1<<20
using namespace std;
typedef long long ll;
int N;
bool P[1<<20];

ll gcd(ll a, ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}


void solve(){
	fill(P,1);
	cin>>N;
	for(int i=2;i*i<MAX;i++){
		if(P[i]){
			for(int j=i*i;j<MAX;j+=i)
				P[j]=0;
		}		
	}
	vector<int> v;
	for(int i=1;i<=N;i++){
		if(P[i])v.push_back(i);
	}
	long long ans=0;
	cout<<ans<<endl;

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

