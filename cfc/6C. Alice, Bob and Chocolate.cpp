#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N,L,R;
int A[1<<20];
int main(){
   L=R=0;
   scanf("%d",&N);
   for(int i=0;i<N;i++)scanf("%d",&A[i]);
   int x=0,y=N-1;
   int a=0,b=0;
   while(x<=y){
      if(L<=R){
         L+=A[x];x++;       
         a++;
      }else{
         R+=A[y];y--;   
         b++;
      }  
   }
   printf("%d %d\n",a,b);   
   return 0;      
}
