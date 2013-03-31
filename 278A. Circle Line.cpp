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
int N,u,v;
int A[120];

int calc(int u, int v){
    int ans=0;
    for(int i=u;i!=v;i=(i+1)%N)ans+=A[i];
    return ans;
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&N);
   REP(i,N)scanf("%d",&A[i]);
   scanf("%d %d",&u,&v);u--;v--;
   int ans=min(calc(u,v),calc(v,u));
   printf("%d\n",ans);      
   return 0;      
}
