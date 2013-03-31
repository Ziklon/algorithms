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
char table[41][41];
int dp[41][41];
int m,n;

int go(int p, int q){
	if(p==0&& q==0)return 1;
	if(p<0 || q<0)return 0;
	int& ref=dp[p][q];
	if(ref!=-1)return 0;
	ref=0;
	if(table[p-1][q]=='.')
		ref+=go(p-1,q);
	if(table[p][q-1]=='.')
		ref+=go(p,q-1);
	return ref;	
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(cin>>m>>n){
  	if(m==0&&n==0)break;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>table[i][j];
	mem(dp,-1);
	int dev=go(m-1,n-1);
	cout<<dev<<endl; 
  }
  system("pause");
  return 0;
}
