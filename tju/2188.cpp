#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz size()


int dat[10]={1,2,6,24,120,720,5040,40320,362880,3628800};

bool isd(int p){
   for(int i=1;i<(1<<p);i++){
      int a=0;
      for(int j=0;j<10;j++)
         if((i&(1<<j))!=0)
            a+=dat[j];
      if(a==p)return 1;
   }
   return 0;
}

int main(){
   int X,Y;
   while(cin>>X>>Y){
      if(X==0 && Y==0)break;
      if(isd(X) && isd(Y))
         printf("Yes\n");
      else
         printf("No\n");   
   }
   return 0;


}
