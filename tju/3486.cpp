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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
int dp[7][101][101];

int go(int p, int c,int k){
	if(c==0 && k==0)return 1;
	if(p>=7 || c<0 || k<0)return 0;	
	int& ref=dp[p][c][k];
	if(ref!=-1)return ref;
	ref=0;
	ref=go(p+1,c,k)+go(p,c-p,k-1);
	return ref;
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int T,n,m;
  double dev;
  cin>>T;
  
  memset(dp,-1,sizeof(dp));
  
  while(T){
	cin>>n>>m;
	dev=go(1,m,n);
	dev=dev/(n*6.0);
	printf("%0.2f\n",dev);
	T--;			
  }
  return 0;
}
