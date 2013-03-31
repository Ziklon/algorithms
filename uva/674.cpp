#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
using namespace std;
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
int coins[5]={1,5,10,25,50};
long long dp[9001];
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);  
  int n;
  dp[0]=1;
  REP(i,0,5){
	REP(j,coins[i],9000){
		dp[j]+=dp[j-coins[i]];
	}	
  }
  while(scanf("%d",&n)==1){           
	printf("%lld\n",dp[n]);
  }
  return 0;
}
