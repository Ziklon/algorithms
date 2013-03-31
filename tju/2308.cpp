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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
typedef long long ll;
ll Combi(int n, int k){
	ll dev=1;
	int top=(n-k);
	int h=2;
	for(int j=k+1;j<=n;j++){
		dev*=j;
		while(dev>1 && dev%h==0 && h<=top){
			dev/=h;
			h++;	
		}
	}
	for(;h<=top;h++)
		dev/=h;
	return dev;	
}

ll divs(ll n){
	int dev=1;
	for(int i=2;i*i<=n;i++){
	   int c=0;
	   while(n%i==0){
			n/=i;
			c++;	
	   }
	   dev*=(c+1);
	}
	if(n>1)dev*=2;
	return dev;	
}
ll dev;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n,k;
  while(cin>>n>>k){
	  if(n-k>k)
	  	dev=Combi(n,n-k);
	  else
	  	 dev=Combi(n,k)  ;
  	  cout<<divs(dev)<<endl;
  }
  return 0;
}
