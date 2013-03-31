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



void solve(){
	int ans=0;
	int div=1;
	int A[1005];
	int mx=0;
	for(int i=1;i<1001;i++){
		int mod=1*div;
		set<int> S;
		int aux=0;
		REP(j,0,1000000){			
			mod=(mod*10)%i;
			//cout<<mod<<endl;
			if(S.count(mod)){
				aux=j-A[mod];
				if(aux>mx){
					mx=aux;
					ans=i;
				}break;
			}else{
				S.insert(mod);
				A[mod]=j;
			}
		}//cout<<endl;
		if(i==7)cout<<aux<<endl;
	}
	cout<<ans<<endl;
	cout<<mx<<endl;
	
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

