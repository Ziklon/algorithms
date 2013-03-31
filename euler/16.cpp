#include <iostream>

#define sz size()
using namespace std;

string mul(string a, string b){
   if(a.sz<b.sz)
      swap(a,b);
   for(int i=0;i<b.sz;i++){
      string x="";
      int ll=0;
      for(int j=0;j<a.sz;j++){
         int r=(a[j]-'0')*(b[i]-'0');
         if(r+ll>9){
            
         }
      }
   }
   

}

int main(){


   return 0;
}
