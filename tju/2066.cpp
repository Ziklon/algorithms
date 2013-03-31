#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

bool greeater(string a, string b){
   if(a.size()!=b.size())return (a.size()>b.size());
   for(int i=0;i<a.size();i++){
      if(a[i]<b[i])
         return 0;
   }
   return 1;
}

int main(){
  int N;
  string a, b;
  cin>>N;
  while(N){
   cin>>a>>b;  
   if(greeater(a,b))
      printf("MMM BRAINS\n");
   else
      printf("NO BRAINS\n");
   N--;
  }
  return 0;
}
