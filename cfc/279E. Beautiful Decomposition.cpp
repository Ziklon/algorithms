#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char cad[1<<20];

int main(){
   int ans=0;
   scanf("%s",cad);
   int N=strlen(cad);   
   for(int i=0;i<N;i++){
      if(cad[i]=='1'){
        int j=i;
        while(j<N && cad[j]=='1')j++;
        if(j-i>1)
            ans+=2;
        else 
            ans+=1;
        if(j+1<N && cad[j+1]=='1' && (j-i)>1){
            cad[j]='1';
            ans--;
            j--;
        }
        i=j;
      }     
   }   
   printf("%d\n",ans);   
   return 0;      
}
