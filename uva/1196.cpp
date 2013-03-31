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
pair<int,int> I[10005];
pair<int,int> T[10005];
int INF=1<<30;
int main(){
    // clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int N,X,ans,R;
	while(scanf("%d",&X)!=EOF && X){
		//fill(dp,1);		
		REP(i,0,X){
			scanf("%d %d",&T[i].first,&T[i].second);	
			LIS[i]=1;			
		}
		sort(T,T+X);
		I[0]=make_pair(-INF,-INF);
		REP(i,1,X+2)I[i]=make_pair(INF,INF);		
		for(int i=0;i<X;i++){
			int hih=X;
			int low=0;
			while(low<=hih){
				int mid=(low+hih)/2;
				if(I[mid].first<=T[i].first && I[mid].second<=T[i].second)
					low=mid+1;
				else
					hih=mid-1;
			}
			I[low]=T[i];
			LIS[i]=low;
		}	
		ans=0;
		REP(i,0,X)ans=max(LIS[i],ans);

		printf("%d\n",ans);
		
		
	}
	printf("*\n");
	// fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
