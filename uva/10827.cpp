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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<20
using namespace std;
typedef long long ll;
#define MAX 105
int A[MAX][MAX],N,sum[MAX],ans,xx,yy,T;
int main(){
		scanf("%d",&T);
	  while(T--){
	   scanf("%d",&N);
	   int rr=-INF;
	   for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				scanf("%d",&A[i][j]);
				rr=max(rr,A[i][j]);
			}
		
	   
	   if(rr>=0)rr=0;
	   
	   int max_ending_here, max_so_far, maximum = -INF;

	   for (int startx = 0; startx < N; startx++) {
			memset(sum, 0, N * sizeof(int));

			for (int x = startx; x < N; x++) {
				max_ending_here = rr;
				max_so_far = -INF;

				for (int y = 0; y < N; y++) {
					sum[y] += A[x][y];
					max_ending_here = max(rr, max_ending_here + sum[y]);
					max_so_far = max(max_so_far, max_ending_here);
				}
				maximum = max(maximum, max_so_far);
			}
		}
	   ans=maximum;
       
	   printf("%d\n",ans);
   }
   return 0;
}
