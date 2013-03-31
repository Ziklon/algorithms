#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
#define MAXN 1000005
typedef unsigned long long hash;
 
char cad[MAXN];
hash h_forw[MAXN],h_back[MAXN],h_pow[MAXN];
int N;
void build_hash(){
    h_forw[0]=0;
    for(int i=1;i<=N;i++)
        h_forw[i]=(h_forw[i-1]*33)+(cad[i-1]-'a');
}
hash get_hash(int a, int b){
    return h_forw[b]-h_forw[a]*h_pow[b-a];
}
int main(){
    freopen("D:/input.txt","r",stdin);
    while(scanf("%s",cad)==1){
         if(cad[0]=='.')break;
         h_pow[0]=1;
         for(int i=1;i<MAXN;i++)h_pow[i]=h_pow[i-1]*33;         
         N=strlen(cad);
         build_hash();
         vector<int> V;
         int d=0;
         for (int i = 1; i*i <= N; i++){
             if(N%i==0){
                V.push_back(i);
                V.push_back(N/i);
             }
         }
         sort(V.begin(),V.end());
         int maximo=0;
         bool b=true;
         hash aa,bb;
         for (int i = 0; i < V.size(); i++){
            int k=V[i];
            b=true;
            aa=get_hash(0,k);            
            maximo=N/k;
            for (int j = 1; j*k< N; j++){                
                bb=get_hash(k*j,k*(j+1));
                if(aa!=bb)b=false;
            }
            if(b)break;
         }         
         printf("%d\n",maximo);
   }
   return 0;      
}
