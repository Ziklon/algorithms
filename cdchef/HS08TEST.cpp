#include <iostream>
#include <cstdio>
using namespace std;
int R;
float A;
int main(){
   cin>>R>>A;
   if(A-R>=.5 && R%5==0){
      printf("%.2f\n",(A-R-0.5));
   }else
      printf("%.2f\n",A);
   return 0;
}
