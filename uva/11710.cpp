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
#define MAX 410
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
map<string,int>M;
int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int R,C,S,W,c;
    string res="";
    char A[15],B[15];
    while(scanf("%d %d",&C,&R)){
        if(R==C && C==0)break;
        for(int i=0;i<MAX;i++)make(i);
        vector<edge>v;
        M.clear();
        for(int i=0;i<C;i++){            
            scanf("%s\n",A);
            M[A]=i+1;
        }
        //print("hello");
        for(int i=0;i<R;i++){
            scanf("%s %s %d\n",A,B,&c);
            edge ed(M[A],M[B],c);
            v.pb(ed);
        }
        
        scanf("%s\n",A);        
        sort(all(v),orden);
        W=0;
        S=0;
        for(int i=0;i<v.sz;i++)
            if(find(v[i].a)!=find(v[i].b)){
                join(v[i].a,v[i].b);
                W+=v[i].w;
                S++;
            }
        if(S!=C-1)
            print("Impossible");
        else
            print(tos(W));
        
    }
    return 0;

}


