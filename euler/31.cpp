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

int C[]={1,2,5,10,20,50,100,200};
long long dp[205];

long long ans;
int main(){
    clock_t tStart = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	dp[0]=1;
	for(int i=0;i<8;i++){
		for(int j=C[i];j<205;j++){
			dp[j]+=dp[j-C[i]];
		}	
	}
	
	cout<<dp[200]<<endl;
	printf("Time taken: %dms\n", (clock() - tStart));
	return 0;
}
