#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int A[2000001];
int n,k;
int main(){
   while(scanf("%d",&n)){
      if(n==0)break;
      for(int i=0;i<n;i++)scanf("%d",&A[i]);
      sort(A,A+n);
      printf("%d",A[0]);
      for(int i=1;i<n;i++)printf(" %d",A[i]);
      printf("\n");
      
   }
   return 0;
}
