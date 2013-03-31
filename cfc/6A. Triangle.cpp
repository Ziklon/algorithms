#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
   vector<int> v(4);
   for(int i=0;i<4;i++)scanf("%d",&v[i]);
   
   sort(v.begin(),v.end());
   
   bool Triangle=0;
   bool Segment=0;
   for(int mask=0;mask<(1<<4);mask++){
        if(__builtin_popcount(mask)==3){
           vector<int> tmp;         
           for(int i=0;i<4;i++)
             if(mask&(1<<i))tmp.push_back(v[i]);
           
           if(tmp[0]+tmp[1]>tmp[2])Triangle=1;
           if(tmp[0]+tmp[1]==tmp[2])Segment=1;            
        }    
   }
   if(Triangle)puts("TRIANGLE");
   else if(Segment)puts("SEGMENT");
   else puts("IMPOSSIBLE");      
   return 0;      
}
