#include <iostream>
#include <cstdio>

using namespace std;
int N;
int f19(int n){
   if(n<=100)return f19(f19(n+11));
   return n-10;

}
int main(){
   while(1){
      scanf("%d\n",&N);
      if(N==0)return 0;
      printf("f91(%d) = %d\n",N,f19(N));   
   }
   return 0;
}
