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
int cnt(string& s, char c){
	int dev=0;
	for(int i=0;i<s.sz;i++)
		if(s[i]==c)
		dev++;
	return dev;	
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int T;
  string a,b,c;
  cin>>T;
  while(T--){
	c="";
	cin>>a>>b;
	for(int i=0,j=0;i<b.sz&&j<a.sz;j++){
		if(c==b)break;
		if(a[j]==b[i])
			c+=a[j],i++;
	}
	if(c==b)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
			
  }
  //system("pause");
  return 0;
}
