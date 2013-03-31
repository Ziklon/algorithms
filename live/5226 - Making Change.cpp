#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int C[7],V;
double camb;
int T[]={5,10,20,50,100,200};

int get_num_a(int suma){
    int ans=0;
    int idx=5;
    while(idx>=0){
        if(T[idx]>suma){
            idx--;
        }else{
            ans++;
            suma-=T[idx];
        }
    }
    return ans;
}
int get_num_b(int suma){
    int ans=0;
    int idx=5;
    int M[7];
    for(int i=0;i<7;i++)M[i]=C[i];
    
    while(idx>=0){
        if(M[idx]==0 || T[idx]>suma){
            idx--;
        }else{
            ans++;
            suma-=T[idx];
            M[idx]--;
        }
    }
    if(suma>0)return -1;
    return ans;    
}




int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(1){
        bool flag=0;
        for(int i=0;i<6;i++){
            cin>>C[i];
            if(C[i]!=0)flag=1;
        }
        if(flag==0)break;
        cin>>camb;        
        V=((camb*100.0)+.5);        
        int ans=1<<20;
        for(int i=V;i<=1000;i+=5){
            int aa=get_num_b(i);
            int bb=get_num_a(i-V);
            if(aa>-1)ans=min(ans,aa+bb);
        }
        printf("%3d\n",ans);    
        
   }
   return 0;      
}
