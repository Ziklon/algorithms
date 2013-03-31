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
int coins[4]={1,5,8,14};
int dp[5][500001],N;
int go(int p, int c){
	if(p>=4 || c<0)return 1<<30;
	if(c==0)return 0;
	int& ref=dp[p][c];
	if(ref!=-1)return ref;
	ref=min(go(p+1,c),1+go(p,c-coins[p]));
	return ref;	
}


int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  mem(dp,-1);
  while(cin>>N){
  	if(N==-1)break;
  	cout<<go(0,N)<<endl;
  }
  //system("pause");
  return 0;
}
