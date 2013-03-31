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
typedef unsigned long long hash;
#define MAXN 100006
char pattern[MAXN],text[MAXN];
int N,M,B=33,ans,T;
hash h_pow[MAXN],h_pat[MAXN], h_text[MAXN],aa;

void make(){
    h_pow[0]=1;
    REP(i,MAXN)if(i>0)h_pow[i]=h_pow[i-1]*B;
    
    h_pat[0]=h_text[0]=0;    
    for(int i=0;i<N;i++)h_pat[i+1]=(h_pat[i]*B)+(pattern[i]-'a');
    for(int i=0;i<M;i++)h_text[i+1]=(h_text[i]*B)+(text[i]-'a');   

}

int LCP(int a, int b){
    int low=a;
    int hih=b+1;
    int tam;
    while(hih-low>1){
        int mid=(low+hih)>>1;
        tam=mid-a+1;
        aa=h_text[mid]-h_text[a]*h_pow[mid-a];
        if(h_pat[mid]==aa){
            low=mid;
        }else
            hih=mid;
    }
    return low;
}


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d\n",&T); 
   REP(t,T){
        scanf("%s\n",pattern);
        scanf("%s\n",text);
        N=strlen(pattern);
        M=strlen(text);
        make();
        ans=0;
        for(int i=0;i+N<=M;i++){
            ans+=LCP(i,i+N);             
        }
        printf("%d\n",ans);
   }
   return 0;      
}

