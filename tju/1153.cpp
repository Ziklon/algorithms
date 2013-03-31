#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
   int N;
   string line,a,c;
   scanf("%d\n",&N);   
   while(N){
      getline(cin,line);
      a="";c="";
      for(int i=0;i<line.size();i++){
         if(!isalpha(line[i])){
            a=a+c;
            a+=' ';
            c="";
         }else{
            c=line[i]+c;         
         }      
      }
      a=a+c;
      printf("%s\n",a.c_str());
      N--;   
   }

}
