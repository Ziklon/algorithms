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
bool ispal(string s){
	string a=s;
	reverse(all(a));
	return s==a;
}
void solve(){
	string cad;
	cin>>cad;
	string ans="";
	REP(mask,0,1<<cad.sz){
		string aux="";
		REP(i,0,cad.sz){
			if(mask&(1<<i))
				aux+=cad[i];
		}
		if(ispal(aux)&&(ans=="" || ans<aux)){
			ans=aux;
		}
	}
	cout<<ans<<endl;
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

