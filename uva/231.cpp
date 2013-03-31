#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
int data[10000];
int dp[10000];
int N;
int T=0;
int go(int p){
	if(p>=N)return 0;
	int& ref=dp[p];
	if(ref!=-1)return ref;
	ref=0;
	for(int i=p+1;i<N;i++)
		if(data[p]<data[i])
			ref=max(ref,go(i)+1);
	return ref;
}

int main() {
	//freopen("/home/ziklon/in","r",stdin);
	int p=0,n,dev;
	T=1;
	while(cin>>n && n!=-1){
		data[1]=n;
		data[0]=0;
		p=2;
		N=2;
		if(T>1)printf("\n");
		while(cin>>n && n!=-1){
			data[p++]=n;
			N++;
		}
		fill(dp,-1);
		dev=go(0);
		reverse(data+1,data+N);
		fill(dp,-1);
		dev=max(dev,go(0));
		printf("Test #%d:\n",T++);
		printf("  maximum possible interceptions: %d\n",dev);
	}

	return 0;
}

