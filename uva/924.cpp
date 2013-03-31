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
void print(string s){
     printf("%s\n",s.c_str());
     cerr<<s<<endl;
}
#define MAX 2510
vector<int> adj[MAX];

struct nodo{
    int x,d;
    nodo(int _x,  int _d){
        x=_x;
        d=_d;
    }
};

int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int n,m,x,t;
    scanf("%d\n",&n);
    mem(adj,0);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        adj[i].clear();
        for(int j=0;j<m;j++){
            scanf("%d",&x);
            adj[i].pb(x);
        }
        scanf("\n");
    }
    scanf("%d\n",&t);
    
    for(int i=0;i<t;i++){
        scanf("%d\n",&x);
        vector<bool>vis(n,0);
        vector<int>day(n,0);
        queue<nodo>Q;
        Q.push(nodo(x,1));
        vis[x]=1;
        int M=0,D=0;
        while(!Q.empty()){
            nodo cur=Q.front();
            Q.pop();
            int cnt=0;
            for(int j=0;j<adj[cur.x].sz;j++)
                if(!vis[ adj[cur.x][j] ])
                    cnt++;
            day[cur.d]+=cnt;
            
            for(int j=0;j<adj[cur.x].sz;j++)
                if(!vis[adj[cur.x][j]]){
                    Q.push(nodo(adj[cur.x][j],cur.d+1));
                    vis[adj[cur.x][j]]=1;
                }
        }
        for(int j=1;j<n;j++)
            if(day[j]>M){
                M=day[j];
                D=j;
            }
        if(M==0)
            print("0");
        else{
            stringstream ss;
            ss<<M<<" "<<D;
            print(ss.str());
        }
    }    
    return 0;
}


