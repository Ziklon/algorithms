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
#define MAXN 512005
hash h_pat[300],h_pow[MAXN],h_text[MAXN];

string patt;
string text;
int N,M,ans,idx;

hash get_hash(int a, int b){
    return h_text[b]-h_text[a]*h_pow[b-a];
}

int get_val(char c){
    if(c>='a' && c<='z')return c-'a';
    if(c>='A' && c<='Z')return c-'A'+26;
    return 53;
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(getline(cin,patt)){
       getline(cin,text);
       N=patt.size();
       M=text.size();
       h_pow[0]=1;
       h_pat[0]=0;
       REP(i,MAXN)if(i>0)h_pow[i]=h_pow[i-1]*79;       
       REP(i,N)h_pat[i+1]=(h_pat[i]*79)+(get_val(patt[i]));
       h_text[0]=0;   
       ans=0,idx=0;          
       REP(i,M){
           h_text[idx+1]=(h_text[idx]*79)+(get_val(text[i]));
           idx++;       
           if(idx>=N && get_hash(idx-N,idx)==h_pat[N]){
                idx-=N;
                ans++;
           }   
       }
       printf("%d\n",ans);
   }
   return 0;      
}
