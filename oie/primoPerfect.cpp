#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#define MAX 40010
bool crb[MAX];
int N,K,Z,i,j;
int main(){
  memset(crb,1,sizeof(crb));
  crb[0]=0;
  crb[1]=0;
  for(i=2;i*i<=MAX;i++)
      if(crb[i])
         for(j=i*2;j<=MAX;j+=i)
             crb[j]=0;
      
  while(scanf("%d",&N)){
      if(N==0)break;
      bool ok=crb[N];
      while(N>=10 && ok){
         Z=0;
         while(N){
            Z+=N%10;
            N/=10;
         }
         ok=ok&&crb[Z];
         N=Z;      
      }
      ok=ok&&crb[N];
      if(ok)printf("yes\n");
      else  printf("no\n");  
  } 
  return 0;
}
