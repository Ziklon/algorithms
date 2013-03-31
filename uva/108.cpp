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
#define INF 1<<30
using namespace std;
typedef long long ll;
#define MAX 105
int A[MAX][MAX],N,dp[MAX][MAX],ans,xx,yy,T;
int main(){
	scanf("%d",&N);
	   ans=-1<<29;
	   for(int i=0;i<N;i++)
		  for(int j=0;j<N;j++)
			 scanf("%d",&A[i][j]);
	   
	   for(int i=0;i<N;i++){
		  dp[i][0]=A[i][0];
		  for(int j=1;j<N;j++)
			 dp[i][j]=A[i][j]+dp[i][j-1];      
	   }
	   for(int i=0;i<N;i++)
		  for(int j=i;j<N;j++){
			int sum=-1<<29;
			for(int k=0;k<N;k++){
				int temp=dp[k][j]-dp[k][i]+A[k][i];
				sum=max(sum+temp,temp);
				ans=max(sum,ans);       
			}      
		  }      
	   printf("%d\n",ans);
   return 0;
}
