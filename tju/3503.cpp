#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;
int dat[10001];
int main(){
   int N,V,k;
   scanf("%d\n",&N);   
   while(N){
      memset(dat,0,sizeof(dat));
      scanf("%d",&V);
      for(int i=0;i<V;i++){
         scanf("%d",&k);
         dat[k]++;
      }
      sort(dat,dat+10001);
      printf("%d\n",dat[10001-1]);
      N--;   
   }

}
