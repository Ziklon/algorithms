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
#define INF 1<<30
using namespace std;
typedef long long ll;
int N,R,Q,x,y,T;
int A[50005],B[50005],d,n;




void solve(){
	T=1;
	while(scanf("%d",&N)==1 && N){
		REP(i,0,N){
			A[i+1]=i+1;
			B[i+1]=i+1;
		}
		
		scanf("%d",&R);		
		REP(i,0,R){
			scanf("%d %d",&x,&y);
			x=B[x];
			y=B[y];
			if(x>y)swap(x,y);
			while(x<=y){
				swap(A[x],A[y]);
				B[A[y]]=y;
				B[A[x]]=x;
				x++;	
				y--;
			}	
		}
		scanf("%d",&Q);
		printf("Genome %d\n",T);
		REP(i,0,Q){
			scanf("%d",&x);
			printf("%d\n",A[x]);		
		}
		T++;
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


