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


struct edge{
    int x;
    double w;
    edge(int _x, double _w){
        x=_x;
        w=_w;
    }

};
bool operator<(edge p, edge q){
    return p.w>q.w;
}

vector<edge>adj[1001];
bool vis[1001];
double dis[1001];
double oo=1e+30;

int c,r;
double nch,ntr,h;
double prim(){
    for(int i=0;i<c;i++){
        dis[i]=oo;
        vis[i]=0;
    }
    priority_queue<edge>Q;
    dis[0]=0;
    Q.push(edge(0,0.0));
    nch=0;
    ntr=0;
    vis[0]=0;
    while(!Q.empty()){
        edge cur=Q.top();
        Q.pop();
        vis[cur.x]=1;
        for(int i=0;i<adj[cur.x].size();i++){
            edge next=adj[cur.x][i];
            if(vis[next.x])continue;
            if(next.w<dis[next.x]){
                dis[next.x]=next.w;
                Q.push(edge(next.x,dis[next.x]));
            }
        }
    }
    double dev=0;
    for(int i=1;i<c;i++){
        if(dis[i]>r*1.0)
            ntr+=dis[i];
        else
            nch+=dis[i];
        dev+=dis[i];
    }
    return dev;

}

int main(){
    //freopen("/home/ziklon/in","r",stdin);
    //freopen("/home/ziklon/out","w",stdout);
    int n,t=1,x,y,st;
    int aa,bb,res;
    scanf("%d\n",&n);
    while(n--){
        scanf("%d %d",&c,&r);
        vector<pair<int,int> >citys;
        for(int i=0;i<c;i++){
            scanf("%d %d",&x,&y);
            citys.push_back(make_pair(x,y));
            adj[i].clear();
        }
        st=0;
        mem(vis,0);
        for(int i=0;i<c;i++){
            for(int j=i+1;j<c;j++){
                h=hypot(citys[i].first-citys[j].first,citys[i].second-citys[j].second);
                adj[i].push_back(edge(j,h));
                adj[j].push_back(edge(i,h));
                if(h<=r*1.0)vis[j]=1;
            }
            if(!vis[i])st++;
        }
        res=round(prim());
        aa=round(nch);
        //bb=round(ntr+1e-6);        
        bb=res-aa;
        //cout<<"Case "<<(t++)<<": "<<st<<" "<<(int)nch<<" "<<(int)ntr<<endl;
        //cerr<<"Case "<<(t++)<<": "<<st<<" "<<(int)nch<<" "<<(9ntr<<endl;
        //cerr<<nch<<" "<<ntr<<endl;
        printf("Case #%d: %d %d %d\n",t++,st,aa,bb);
    }

    return 0;

}


