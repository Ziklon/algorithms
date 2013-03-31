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
#define MAXN 100005
int T,N,A[MAXN],ans;
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        REP(i,N)scanf("%d",A+i);
        
        sort(A,A+N);
        ans=0;
        for(int i=0;i+1<N;i++)ans+=A[i];        
        printf("%d\n",ans);
        
   }
   return 0;      
}
