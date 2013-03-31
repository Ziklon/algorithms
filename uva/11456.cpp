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
using namespace std;
int LIS[2005];
int LDS[2005];
int T[2005];
int main(){
    // clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int N,X,ans;
	scanf("%d",&N);
	REP(k,0,N){
		//fill(dp,1);
		scanf("%d",&X);
		REP(i,0,X){
			scanf("%d",&T[i]);	
			LIS[i]=1;
			LDS[i]=1;
		}
		for(int i=X-1;i>=0;i--)
			REP(j,i+1,X){
				if(T[i]<T[j])LIS[i]=max(LIS[i],LIS[j]+1);
				if(T[i]>T[j])LDS[i]=max(LDS[i],LDS[j]+1);
			}
		ans=0;
		REP(i,0,X)ans=max(ans,LIS[i]+LDS[i]-1);
		printf("%d\n",ans);
		
		
	}
	// fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
