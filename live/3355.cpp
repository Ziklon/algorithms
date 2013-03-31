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
#define MAX 150000
using namespace std;
int A[MAX+100];
int x,s,n;
void solve(){
	REP(i,0,MAX)A[i]=INF;
		
	REP(i,1,MAX){
		x=i;
		s=0;
		while(x>0){
			s+=x%10;
			x/=10;
		}
		A[i+s]=min(A[i+s],i);		
	}
	scanf("%d",&n);
	REP(i,0,n){
		scanf("%d",&x);
		s=A[x]>=INF?0:A[x];
		printf("%d\n",s);
	}
	
	
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

