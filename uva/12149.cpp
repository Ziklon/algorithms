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
int n;
ll dp[104];
int main(){
	ios::sync_with_stdio(false);
	dp[0]=0;
	for(int i=1;i<=100;i++){
		dp[i]=(i*i)+dp[i-1];
	}
	while(cin>>n && n){
		cout<<dp[n]<<endl;
	} 	
	return 0;
}

