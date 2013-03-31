#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<20
using namespace std;
long long N,a,b;
long long low,hih,mid,tip,ans,res;
void solve(){
	while(cin>>N>>a>>b){
	
		if(a>b)
			swap(a,b);
		low=0;
		hih=1LL<<32;
		while(low+1<hih){
			mid=(low+hih)/2;
			tip=(mid/a)+(mid/b);
			if(tip>=N){
				hih=mid;
			}else{
				low=mid+1;
			}			
		}
		long long vc=hih/a;
		if(hih%b!=0)	
			ans=hih+((b*vc)-hih);
		else
			ans=hih;
		
		res=(vc)+(ans/b);
		cout<<res<<" "<<ans<<endl;
	}
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

