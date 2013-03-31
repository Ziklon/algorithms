#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <functional>
#include <numeric>
using namespace std;
#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int a,b,n;
    long long dev=0,ant=1,des=1;  
    while(cin>>a>>b>>n){
     if(a==0 && b==0 && n==0)break;
     for(int i=2;i<=n;i++){   
       dev=(a*ant+b*des)%7;
       des=ant;
       ant=dev;       
     }
     if(n<=2) cout<<1<<endl;
     else  cout<<dev-1<<endl;  
    }
    return 0;
}
