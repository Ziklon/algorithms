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

int A[102];
int dp[10005];
int N,I;
double val;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&N,&I)==2 && N && I){
		
		REP(i,1,N+1){
			int a, b;
			scanf("%d.%d",&a,&b);
			A[i]=(100*a)+b;			
		}
		int res=5001-A[I];
		if(res<=0){
			printf("100.00\n");
			continue;
		}
		//dp
		fill(dp,0);
		dp[0]=1;
		for(int i=1;i<=N;i++){
			if(i==I)continue;
			for(int j=10000;j>=1;j--){
				if(j>=A[i])
					dp[j]|=dp[j-A[i]];
			}
		}
		for(int i=res;i<=10000;i++)if(dp[i]){
			val=i;
			break;
		}
		val=(A[I]*100.0)/(A[I]+val);
		printf("%0.2f\n",val);
	}
	return 0;
}
