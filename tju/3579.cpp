#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;
vector<int> V;
int P,Q;
int main(){
   while(scanf("%d %d",&P,&Q)==2){
      V.clear();
      
      for(int i=1;i<=Q;i++)
         if(Q%i==0)
            V.push_back(i);
            
      for(int i=1;i<=P;i++)
         if(P%i==0){
            for(int j=0;j<V.size();j++)
               printf("%d %d\n",i,V[j]);
         }
      
   }   
   return 0;
}
