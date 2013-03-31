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
int T,N,ans,tmp;

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        ans=1;
        scanf("%d",&N);
        for(int i=2;i*i<=N;i++){
            tmp=0;
            while(N%i==0){
                tmp++;
                N/=i;
            }
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
   }
   return 0;      
}
