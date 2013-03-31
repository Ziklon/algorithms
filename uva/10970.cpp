#include <iostream>

using namespace std;

int cutts(int a, int b){
   if(a<=b && a>1)
      return 1+(cutts(a/2,b)+cutts(a-(a/2),b)); 
   if(b<=a && b>1)
      return 1+(cutts(a,b/2)+cutts(a,b-(b/2))); 
   if(a==1 && b>1)return b-1;
   if(b==1 && a>1)return a-1;
   return 0;
}


int main(){
   int m,n;
   while(cin>>n>>m){
      cout<<cutts(n,m)<<endl;
   }   
   return 0;

}
