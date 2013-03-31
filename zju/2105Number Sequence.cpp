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
#define MOD 7
typedef long long ll;

typedef vector<int> vi;

int sz;
int N,A,B;


vector<vi> multi(vector<vi> a, vector<vi> b){
    vector<vi> ans(sz,vector<int>(sz));
    REP(i,sz)
        REP(j,sz){
            int sum=0;
            REP(k,sz)sum+=(a[i][k]*b[k][j]);
            ans[i][j]=sum%MOD;
        }
    return ans;
}

vector<vi> pow_mat(vector<vi> v, int n){
    vector<vi> ans=v;    
    while(n>0){
        if(n&1)ans=multi(ans,v);
        v=multi(v,v);
        n>>=1;        
    }
    return ans;
}


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(scanf("%d %d %d",&A,&B,&N)==3){
        if(A==B && B==N && A==0)break;
        vector<vi> v(2,vector<int>(2,0));
        v[0][0]=A;
        v[0][1]=B;
        v[1][0]=1;        
        sz=2;                
        if(N>2){
                v=pow_mat(v,N-3);              
                int ans=(v[0][0]+v[0][1])%MOD;                
                printf("%d\n",ans);        
                
        }else{
                printf("%d\n",1);
        }
   } 
   
   
   return 0;      
}
