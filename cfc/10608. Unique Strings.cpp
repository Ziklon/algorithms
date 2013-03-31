#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
#define NMAX 100000000000000LL
#define LEN 60

ll dp[LEN+1][LEN+1],N;
ll S[LEN+1];
int M;

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   for(int i=0;i<=LEN;i++)dp[i][i]=dp[i][0]=1;
   for(int i=2;i<=LEN;i++)for(int j=1;j<i;j++)dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
   S[0]=0;
   S[1]=2;
   S[2]=S[1]+4;   
   scanf("%lld",&N);
   
   for(int i=3;i<=LEN;i++){
        S[i]+=S[i-1];
        int mid=i/2;
        S[i]+=2*(dp[i][mid-1]+dp[i][mid]+dp[i][mid+1]);
   }
   
      
   REP(i,60)if(S[i]>=N){
        M=i;
        break;
   }
   cout<<M<<endl;    
   return 0;      
}
