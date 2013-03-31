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
long long N;
long long expo_fast(long long a,long long b){
	if(b==0)return 1;
	long long dev=(expo_fast(a,b/2))%2006;
	dev=(dev*dev)%2006;
	if(b&1)
		dev=(dev*(a%2006))%2006;
	return dev;	
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>N){
  	if(N==0)break;
  	cout<<expo_fast(N,N)<<endl;
  }
  //system("pause");
  return 0;
}
