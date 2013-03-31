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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T,C,N;
   cin>>T;
   for(int i=1;i<=T;i++){
		cin>>N;
		vector<int>v(N);
		for(int j=0;j<N;j++)cin>>v[j];
		int dev=-1;
		sort(all(v));
		for(int j=1;j<N;j++){
			int a=0,b=0;
			int p=0,q=0;
			for(int x=0;x<j;x++){
				a+=v[x];
				p=p^v[x];
			}
			for(int x=j;x<N;x++){
				b+=v[x];
				q=q^v[x];
			}
			if(q==p)dev=max(dev,max(a,b));
		}
		if(dev!=-1)
			printf("Case #%d: %d\n",i,dev);
		else
			printf("Case #%d: NO\n",i);		
		
	}
   
   return 0;
}
