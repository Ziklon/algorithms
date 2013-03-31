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
int LIS[10005];
int LDS[10005];
int I[10005];
int T[10005];
int INF=1<<30;
int main(){
    // clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int N,X,ans,R;
	while(scanf("%d",&X)!=EOF){
		//fill(dp,1);
		
		REP(i,0,X){
			scanf("%d",&T[i]);	
			LIS[i]=1;
			LDS[i]=1;
		}
		
		I[0]=-INF;
		REP(i,1,X+2)I[i]=INF;		
		for(int i=0;i<X;i++){
			int hih=X;
			int low=0;
			while(low<=hih){
				int mid=(low+hih)/2;
				if(I[mid]<T[i])
					low=mid+1;
				else
					hih=mid-1;
			}
			I[low]=T[i];
			LIS[i]=low;
		}
		I[0]=-INF;
		REP(i,1,X+2)I[i]=INF;		
		for(int i=X-1;i>=0;i--){
			int hih=X;
			int low=0;
			while(low<=hih){
				int mid=(low+hih)/2;
				if(I[mid]<T[i])
					low=mid+1;
				else
					hih=mid-1;
			}
			I[low]=T[i];
			LDS[i]=low;
		}
		
		ans=0;
		REP(i,0,X){
			R=min(LIS[i],LDS[i])*2;			
			ans=max(R-1,ans);
		}
		printf("%d\n",ans);
		
		
	}
	// fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
