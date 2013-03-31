#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
long long dp[220][22][23][2];
int N,Q,M,D;
int vals[202];

long long go(int p, int n , int r,int s){
    if(n==M || p>=N){
        if(r==0 && n==M)return 1;
        return 0;
    }
    long long& ref=dp[p][n][r][s];
    if(ref!=-1)return ref;
    ref=0;
    ref+=go(p+1,n,r,s);
    int val=r;
    if(s==0)val*=-1;
    val=(val+(vals[p]%D))%D;
    if(val>=0)
        ref+=go(p+1,n+1,abs(val),1);
    else
        ref+=go(p+1,n+1,abs(val),0);    
    return ref;   

}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    
    int ns=1;
    while(cin>>N>>Q){
        if(N==0 && Q==0)break;
        REP(i,0,N)cin>>vals[i];
        printf("SET %d:\n",ns);
        ns++;
        
        REP(i,0,Q){
            fill(dp,-1);
            cin>>D>>M;
            printf("QUERY %d: %lld\n",i+1,go(0,0,0,1));                   
            
        }
        
        
    }
    //system("pause");
    return 0;
}
