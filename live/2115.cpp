#include <iostream>

using namespace std;
int n,dev;
int main(){
     cin>>n;
     dev=1;
     while(n>1){
         if(n&1)dev*=2;
         n/=2;
     }
     cout<<dev<<endl;
}
