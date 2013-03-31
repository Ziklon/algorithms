#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
#define MAX 1000001
bool sieve[MAX];
bool sump[MAX];

int binary(int& n , vector<int>&v){
    int low=0,higth=30123;
    for(int i=0;i<18;i++){
        int cur=(low+higth)/2;
        if(v[cur]<=n)
            low=cur;
         else
            higth=cur;
    }
    return low;

}

int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    mem(sieve,1);
    mem(sump,0);
    sieve[0]=0;
    sieve[1]=0;
    vector<int>prime;
    for(int i=2;i*i<MAX;i++)
        if(sieve[i])
            for(int j=2*i;j<MAX;j+=i)
                sieve[j]=0;
        for(int i=2;i<MAX;i++){
            if(sieve[i])
                prime.pb(i);
        }

    vector<int>fin;
    for(int i=0;i<prime.sz;i++){
            int x=prime[i],s=0;
            while(x){
              s+=x%10;
              x/=10;
            }
            if(sieve[s])fin.pb(prime[i]);
      }
    int n,a,b;
    scanf("%d\n",&n);
    cerr<<fin.size()<<endl;
    while(n--){
        scanf("%d %d\n",&a,&b);
        int dev=0;
        int baj=binary(b,fin);
        int low=binary(a,fin);
        dev=(baj-low+1);
        if(fin[low]<a)dev--;
        if(fin[baj]>b)dev--;
        //cerr<<low<<" "<<baj<<" - "<<dev<<endl;
        printf("%d\n",dev);
    }

    return 0;

}
