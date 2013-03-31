#include <iostream>
#include <cstdio>

using namespace std;
long long dev=0;
int main(){
   int N,a,b,z;
   while(cin>>N){
      if(N==-1)break;
      z=0;
      dev=0;
      for(int i=0;i<N;i++){
         cin>>a>>b;
         dev+=a*(b-z);
         z=b;
     }
     cout<<dev<<" miles"<<endl;  
   }
   return 0;
}
