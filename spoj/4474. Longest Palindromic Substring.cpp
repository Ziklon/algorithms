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
#define MAXN 100005
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
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   
   scanf("%s\n",cad);   
   
   h_pow[0]=1;
   for(int i=1;i<MAXN;i++)h_pow[i]=h_pow[i-1]*33;
   
   N=strlen(cad);
   build_hash(); 
     
   cout<<get_hash(0,3)<<endl;
   cout<<get_hash(2,5)<<endl;
       
   
   return 0;      
}
