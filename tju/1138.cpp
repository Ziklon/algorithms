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
inline ll combi(ll n, ll k){
	ll dev=1;
	ll h=2;
	ll hs=(n-k); 
	for(ll i=k+1;i<=n;i++){
				dev=dev*i;
			while(dev>1 && h<=hs && dev%h==0){
					dev=dev/h;
					h++;
			}
		}
		for(;h<=hs;h++)
			dev/=h;
	return dev;	
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ll dev=0;
  int A,B;
  while(scanf("%d %d",&A,&B)==2){
  	if(A==0 && B==0)break;
  	if(A-B<B)
  		dev=combi(A,B);
  	else
  		dev=combi(A,A-B);
  	printf("%lld\n",dev);
  }
  return 0;
}
