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
int dp[2][50002],T[5005];
int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int C,H;
	scanf("%d %d",&C,&H);
	REP(i,0,H)scanf("%d",&T[i]);
	
	fill(dp,0);
	//sort(T,T+H);
	//cout<<C<<" "<<H<<endl;
	
	for(int j=0;j<H;j++){    
		int p=(j&1);
        for(int k=1;k<=C;k++){
			if(k>=T[j])
				dp[!p][k]=max(T[j]+ dp[p][k-T[j]],dp[p][k]);	
			else
				dp[!p][k]=dp[p][k];
			//cout<<dp[j][k]<<" "<<j<<" "<<k<<endl;
        }  
    }
	cout<<dp[(H&1)][C]<<endl;
	
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
