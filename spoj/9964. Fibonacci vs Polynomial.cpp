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
#define MOD 1111111111
using namespace std;
typedef long long ll;

ll M[1<<7];
int N,D;
int T;
ll fastExpo(ll a, ll b){
    if(b==0)return 1;
    ll ans=fastExpo(a,b>>1);
    ans=(ans*ans)%MOD;
    if(b&1)ans=(ans*a)%MOD;
    return ans;
}

ll P(ll n){
    ll ans=0;
    REP(i,D+1)
        ans=(ans+M[i]*fastExpo(n,i))%MOD;
    return ans;
}

ll F[200];

struct Matrix{
    vector<vector<ll> > v;
    Matrix(int N){
        v.assign(N,vector<ll>(N,0));
        REP(i,N)v[i][i]=1;      
    }
};

Matrix operator * (Matrix a, Matrix b){
    
    int NN=a.v.size();
    Matrix ans(NN);
    REP(i,NN)
        REP(j,NN){
            ll ret=0;    
            REP(k,NN)
                ret=(ret+a.v[i][k]*b.v[k][j])%MOD;
            ans.v[i][j]=ret;
        }
    return ans;
}

Matrix fastMatrix( Matrix a, Matrix& one, ll n){
    if(n==1)return a;
    Matrix ans=fastMatrix(a,one,n>>1);
    ans=ans*ans;
    if(n&1)
        ans=ans*one;
    return ans;
}



int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   
   F[0]=1;
   F[1]=1;
   scanf("%d %d",&N,&D);
   
   REP(i,D+1)scanf("%lld",&M[i]);
   
   REP(i,200)if(i>1)F[i]=((F[i-1]+F[i-2])%MOD +P(i))%MOD;
   
   
   Matrix ans(3);
   Matrix one(3);
   
   ans.v[0][0]=F[4];
   
   ans.v[1][0]=F[3];
   ans.v[0][1]=F[3];
   
   ans.v[2][0]=F[2];
   ans.v[1][1]=F[2];
   ans.v[0][2]=F[2];
   
   ans.v[2][1]=F[1];
   ans.v[1][2]=F[1];
      
   ans.v[2][2]=F[0];
   
   
   ans=fastMatrix(ans,one,N-10);
   
   
   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)cout<<ans.v[i][j]<<" ";
        cout<<endl;
   }
   
      
   //cout<<ans.v[1][0]<<endl;
    
        
      
   return 0;      
}



