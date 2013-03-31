#include <iostream>
#include <cmath>

using namespace std;

int N,dev,k;
int main(){
   while(cin>>N){
      k=0;
      dev=0;
      while(k!=N){
         k=(N+k+1)/2;
         dev++;      
      }     
      cout<<dev<<endl;   

   }
   return 0;

}
