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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
 int dp[15][190][1121];
int N,K;
int primes[190];

int go(int ns, int index, int sum){
    if(ns==0 && sum==0)return 1;    
    if(index>=187 || sum<=0 || ns<=0)return 0;
    if(dp[ns][index][sum]!=-1)
        return dp[ns][index][sum];
    return dp[ns][index][sum]=go(ns-1,index+1,sum-primes[index])+go(ns,index+1,sum);
    
}


bool isPrime(int n){    
    if(n==2)return 1;
    if(n%2==0)return 0;
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    

    int np=0;
    REP(i,2,1121){
        if(isPrime(i))
            primes[np++]=i;
                       
    }
    fill(dp,-1);
    while(scanf("%d %d",&N,&K)==2){
        if(N==0 && K==0)break;        
        printf("%d\n",go(K,0,N));
    }
    return 0;
}
