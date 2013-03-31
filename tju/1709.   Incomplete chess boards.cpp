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

int N,a,b,c,d;

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&N);
   REP(t,N){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("Scenario #%d:\n",t+1);
        if((((a&1)+(b&1))&1)==(((c&1)+(d&1))&1))printf("%d\n",0);
        else printf("%d\n",1);
        printf("\n");
   }
   return 0;      
}
