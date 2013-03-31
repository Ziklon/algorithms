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
#define oo 1<<30
using namespace std;
int A[4005];

void solve(){
	int n,a,b,c;
	int ans=0;
	
	scanf("%d %d %d %d\n",&n,&a,&b,&c);
	int C[]={a,b,c};
	sort(C,C+3);
	//5 5 3 2
	A[0]=1;
	for(int i=0;i<=n;i++){
		A[i]=0;
		for(int j=0;j<3;j++){
			if(i>=C[j] && A[i-C[j]]>0)
				A[i]=max(A[i],A[i-C[j]]+1);
		
		}	
	}
	ans=A[n]-1;	
	printf("%d\n",ans);
	
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

