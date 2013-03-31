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
double x,y;
bool orden(pair<int,int> a, pair<int,int> b){
	return a.first*b.second<a.second*b.first;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nC,n;
  scanf("%d",&nC);
  for(int i=0;i<nC;i++){
	vector<pair<int,int> >vp;
	scanf("%d",&n);
	 for(int j=1;j<n;j++)
	 	for(int k=j+1;k<=n;k+=1)
		 	if(__gcd(j,k)==1)
				vp.pb(mp(j,k));
			
	sort(all(vp),orden);	
	for(int x=0;x+1<vp.sz;x++)
		printf("%d/%d,",vp[x].first,vp[x].second);	
	printf("%d/%d\n",vp[vp.sz-1].first,vp[vp.sz-1].second);
			
  }
  return 0;
}
