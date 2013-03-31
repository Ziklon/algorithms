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
#define MAX 1010
int P[MAX];
struct edge{
    int a,b,w;
    edge(int _a,int _b, int _w){
        a=_a;
        b=_b;
        w=_w;
    }
};

void make(int n){
    P[n]=n;
}

int find(int n){
    if(P[n]!=n)
        P[n]=find(P[n]);
    return P[n];
}

void join(int a, int b){
    P[find(a)]=b;
}

bool orden(edge p, edge q){
    return p.w<q.w;
}

void print(string s){
    printf("%s\n",s.c_str());
    //cerr<<s<<endl;
}
int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int N,M,A,W,a,b,c,na,x;
    string dev="";
    while(scanf("%d %d",&N,&M)){
        if(N==M && N==0)break;
        
        for(int i=0;i<N+1;i++)make(i);
        vector<edge>v;
        
        for(int i=0;i<M;i++){
            scanf("%d %d %d\n",&a,&b,&c);
            edge ed(a,b,c);
            v.pb(ed);
            
        }
        sort(all(v),orden);
        
        stringstream ss;
        for(int i=0;i<v.sz;i++)
            if(find(v[i].a)!=find(v[i].b)){
                join(v[i].a,v[i].b);
            }else
                ss<<" "<<v[i].w;
        dev=ss.str();
        if(dev.sz==0)
            print("forest");
        else
            print(dev.substr(1));
        
    }
    return 0;

}


