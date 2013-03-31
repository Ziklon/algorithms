#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int B[25],n,k,ans;
int dp[2][25];
int M[25];


int main(){
  freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  
  scanf("%d\n",&n);
  for(int i=0;i<n;i++) scanf("%d",&M[i]);
  while(scanf("%d",&k)!=EOF){
	  B[0]=k;
	  
	  for(int i=1;i<n;i++){
		scanf("%d",&k);
		B[i]=k;
	  }
	  
	  int ii;
      for(int i=n;i>=0;i--){
		ii=i&1;
		for(int j=n;j>=0;j--){
			if(i==n|| n==j){
				dp[ii][j]=0;
				continue;
			}
			if(B[i]==M[j])dp[ii][j]=1+dp[1-ii][j+1];
			else dp[ii][j]=max(dp[1-ii][j],dp[ii][j+1]);
		}
	  }
	  ans=dp[0][0];  
	  printf("%d\n",ans);
	  
      
  }
  return 0;
}
