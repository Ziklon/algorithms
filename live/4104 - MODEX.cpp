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
int T,a,b,n;
int fastExp(int a, int b, int N){
    if(b==0)return 1;
    int ans=fastExp(a,b>>1,N)%N;
    ans=(1LL*ans*ans)%N;
    if(b&1)
        ans=(1LL*ans*a)%N;
    return ans;
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d %d %d",&a,&b,&n);
        printf("%d\n",fastExp(a,b,n));   
   }
   return 0;      
}
