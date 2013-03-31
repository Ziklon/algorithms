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
void print(string s){printf("%s\n",s.c_str());cerr<<s<<endl;}



int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int a[11]={10000, 5000, 2000, 1000,500,200,100,50,20,10, 5};
    long long M[30010];
    int mx=30010;
    for(int i=0;i<mx;i++)M[i]=0;
    sort(a,a+11);
    M[0]=1;
    for(int i=0;i<11;i++){
        for(int j=a[i];j<mx;j++)
               M[j]+=M[j-a[i]];

    }
    //cout<<M[5]<<endl;
    int s,c;
    int x;
    while(scanf("%d.%d",&s,&c)){
        x=(s*100)+c;
        if(x==0)break;
        printf("%3d.%02d%17lld\n",s,c,M[x]);
    }
    return 0;

}


