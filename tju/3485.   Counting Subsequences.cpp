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
#define MAXN 1000005
int T,N,A[MAXN],ans,sum,idx;


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        ans=0;
        sum=0;
        idx=0;
        REP(i,N){
            scanf("%d",A+i);
        }        
        REP(i,N){
            if(sum>=47){
               while(idx<=i && sum>=47){
                    sum-=A[idx];
                    idx++;
               }                
            }
            sum+=A[i];
            if(sum==47)ans++;
            
        }
        printf("%d\n",ans);
   }
   
   return 0;      
}
