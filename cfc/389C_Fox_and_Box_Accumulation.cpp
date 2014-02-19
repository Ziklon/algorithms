#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;
int S[101]={},N,num;

int main(){
    scanf("%d",&N);
    REP(i,N){        
        scanf("%d",&num);
        S[num]++;  
    }
    int ans = 0;
    while(1){
        bool can = false;
        REP(i,101)if(S[i]>0)can=true;
        if(!can)break;
        int adds = 0 ;
        node:
        REP(i,101){
           if(S[i]>0 ){
                if(i>=adds){
                    adds++;
                    S[i]--;
                    goto node;                    
               }           
           }     
        }
        ans++;      
    }    
    printf("%d\n",ans);
    return 0;
}
