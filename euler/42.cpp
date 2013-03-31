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
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;

string cad;

bool is(string cad){
	int sum=0;
	REP(i,1,cad.sz-1)sum+=(cad[i]-'A'+1);
	int n=(int)sqrt(sum*2);
	return (n*(n+1))==2*sum;
}
void solve(){
	cin>>cad;
	REP(i,0,cad.sz)if(cad[i]==',')cad[i]=' ';
	stringstream ss(cad);
	int ans=0;
	while(ss>>cad)ans+=is(cad);
	cout<<ans<<endl;
		
}
int main(){
	#ifdef LocalHost
		freopen("words.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

