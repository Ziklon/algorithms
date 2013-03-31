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
#define MAX 1000000

using namespace std;


long long dp[101][101];
void go(){	
	REP(i,0,101){
		dp[i][0]=1;
		dp[i][i]=1;
	}
	REP(i,1,101){
		REP(j,1,i){
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]);
			dp[i][j]=min(dp[i][j],100000000LL);
		}
	}	
}


int main(){
    clock_t tStart = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int ans=0;
	go();
	REP(i,1,101){
		REP(j,0,i+1){
			if(dp[i][j]>MAX)
				ans++;
		}
	}
	
	cout<<ans<<endl;
	printf("Time taken: %dms\n", (clock() - tStart));
	return 0;
}
