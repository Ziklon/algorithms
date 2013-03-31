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

int main(){
	freopen("out.txt","w",stdout);
	long long T,n,pd,pg,sm;
	cin>>T;
	bool ok=1,a;
	for(int i=1;i<=T;i++){
		cin>>n>>pd>>pg;
		ok=1;
		a=0;
		for(long long j=1;j<=min(100LL,n);j++)
			if(pd>0 && j*100%pd==0)a=1;		
		if(pg==100LL && pd!=100LL)ok=0;
		if(pd>0 && pg==0)ok=0;
		if(!ok || !a)
			printf("Case #%d: Broken\n",i);
		else
			printf("Case #%d: Possible\n",i);
			
	}	
	return 0;
}
