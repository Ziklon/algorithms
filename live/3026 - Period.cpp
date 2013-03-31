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
hash rep_hash(hash S, int m, hash P){
    hash ans=0;
    while(m>0){
        if(m&1)ans=ans*P+S;
        m>>=1;
        S=(S*P)+S;
        P*=P;
    }
    return ans;
}





int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   h_pow[0]=1;
   for(int i=1;i<MAXN;i++)h_pow[i]=h_pow[i-1]*33;
   int Z=1;
   hash aa,bb,cc;
   while(scanf("%d\n",&N)==1 && N){
        scanf("%s\n",cad);                
        build_hash();
        printf("Test case #%d\n",Z++);
        for(int i=1;i*2<=N;i++){
            aa=get_hash(0,i);
            int low=0;
            int hih=N;
            while(hih-low>0){
                int mid=(hih+low)>>1;
                bb=get_hash(0,mid);
                cc=rep_hash(aa,i,h_pow[i]);
                
            }
        }
        
   }    
   return 0;      
}

