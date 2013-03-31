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
#define MAXN 500000
int N,B,tmp,a,b,ans;
int A[MAXN];

bool check(int cnt){
    int need=0;
    REP(i,N){
        if(A[i]<=cnt)need+=1;
        else 
            need+=((A[i]+cnt-1)/cnt);
    }
    return need<=B;
}
int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(scanf("%d %d",&N,&B)==2){
      if(N==-1 && B==-1)break;
      REP(i,N)scanf("%d",&A[i]);
      
      int low=1;
      int hih=1<<30;
      //cout<<"eeeeeee"<<endl;
      while(hih-low>1){
          int mid=(low+hih)>>1;
          //cout<<mid<<endl;
          if(check(mid))
                hih=mid;
          else
                low=mid;
        
      }
      printf("%d\n",hih);            
   }
   
   return 0;      
}
