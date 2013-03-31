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
#define MOD 1000000007
typedef long long ll;

int T,N;
int A[55];
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        REP(i,N)scanf("%d",A+i);
        sort(A,A+N);
        reverse(A,A+N);
        REP(i,N-1){
            A[i]-=(N-i-1);
        }
        int ans=1;
        REP(i,N)ans=(1LL*ans*A[i])%MOD;
        printf("%d\n",ans);
   }
   return 0;      
}
