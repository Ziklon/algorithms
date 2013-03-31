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
typedef long long ll;
ll A,B,ans;
int K;

ll pascal[70][70];
int levelb[70];
string top;

string toBin(ll n){
    
    string ans;
    while(n){
        ans=string(1,'0'+n%2)+ans;
        n/=2;
    }
    return ans;
}

ll combi(int a, int b){
    if(a<=0)return 0;
    if(b<=0)return 0;
    
    return pascal[a][b];
}
ll solve(ll n, int k){
    top=toBin(n);
    ll ans=0;
    int N=top.size();    
    int unos=0;    
    REP(i,N){
       if(top[i]=='1'){
          ans+=combi(N-i-1,k-unos);  
          unos++;                    
       }        
    }
    if(count(top.begin(),top.end(),'1')==k)ans++;    
    return ans;
}

ll get_values(ll M, int K){
    if(M<=0)return 0;
    ll ans=0;
    for(int i=1;i<=60;i++)if(levelb[i]+1==K){
            cout<<i<<" "<<M<<" -> "<<levelb[i]<< " "<<K<<" "<<endl;
    
            ans+=solve(M,i);
    }
    return ans;
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   memset(pascal,0,sizeof pascal);
   
   REP(i,70)pascal[i][i]=pascal[i][0]=1;
   REP(i,70)if(i>1)REP(j,i)if(j>0)pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
   
   levelb[0]=levelb[1]=0;   
   REP(i,70)if(i>1){
       int tmp=i;
       int mov=0;
       while(tmp>1){
            tmp=__builtin_popcount(tmp);
            mov++;
       }
       levelb[i]=mov;       
   }      
   while(scanf("%lld %lld %d\n",&A,&B,&K)==3){
        ans=get_values(B,K)-get_values(A-1,K);
        printf("%lld\n",ans);
    
   }
   return 0;      
}
