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
#define MOD 1000000007
using namespace std;

vector<int> factors(int n){
    vector<int> v;
    bool ok=0;
    for(int i=2;i*i<=n;i++){
        ok=0;
        while(n>0 &&n%i==0){
            ok=1;
            n/=i;
        }
        if(ok)v.push_back(i);
    }
    if(n>1)v.push_back(n);
    return v;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long ans,delta,u;
    int num,h;
    while(scanf("%lld",&num) && num){
        ans=0;
        vector<int> v=factors(num);
        h=1<<v.sz;
        for(int mask=1;mask<h;mask++){
            int P=1;
            REP(i,0,v.sz){
                if(mask&(1<<i))
                    P=P*v[i]/__gcd(P,v[i]);
            }
            if(P<num){
                u=num/P;
                if(num%P==0)u--;
                delta=P*u*(u+1)/2;
                delta%=MOD;
                if(__builtin_popcount(mask)&1)ans+=delta;
                else ans-=delta;
                ans=(ans+MOD)%MOD;
            }
        }
        printf("%lld\n",ans);    
    }
    //system("pause");
    return 0;
}
