#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N,B[8][8];

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   scanf("%d",&N);
   for(int t=0;t<N;t++){
        for(int i=0;i<8;i++)for(int j=0;j<8;j++)scanf("%d",&B[i][j]);
        
        vector<int> v(8,0);
        for(int i=0;i<8;i++)v[i]=i;
        int ans=0;
        do{ 
            bool flag=1;
            for(int i=0;i<8;i++)for(int j=i+1;j<8;j++)if(abs(j-i)==abs(v[j]-v[i]))flag=0;
            
            if(flag){
                int tmp=0;
                for(int i=0;i<8;i++)tmp+=B[i][v[i]];
                ans=max(ans,tmp);             
            }      
        }while(next_permutation(v.begin(),v.end()));
        
        printf("%5d\n",ans);
    
   }
   return 0;      
}

