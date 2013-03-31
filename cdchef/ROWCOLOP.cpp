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
int N,Q,L,X;


char command[23];

ll R[400000],C[400000];
ll ans;

int main(){
   
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif   
   scanf("%d %d",&N,&Q);
   
   REP(i,N+1)R[i]=C[i]=0;
   int mxr=0;
   int mxc=0;
   int idxr=0;
   int idxc=0;
   REP(i,Q){
      scanf("%s %d %d",command,&L,&X);
      if(command[0]=='R'){
         R[L]+=X;
            if(R[L]>mxr)mxr=R[L];
      }         
      else{
         C[L]+=X;
            if(C[L]>mxc)mxc=C[L];
      }
   }   
   cout<<(mxr+mxc)<<endl;           
}
