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

#define MAX 1001


int P[MAX];

int FIND(int x){
   if(P[x]!=x)
      P[x]=FIND(P[x]);
   return P[x];
}
void MAKE(int x){
  P[x]=x;
}
void UNION(int x, int y){
   P[FIND(x)]=FIND(y);
}

struct edge{
   int a,b;
   double w;
   edge(int _a, int _b, double _w){
      a=_a;
      b=_b;
      w=_w;
   }
};

bool orden(edge p, edge q){
   return p.w<q.w;
}

int t,n,k,cn,x,y;
double h;
int main(){
   scanf("%d\n",&t);
   cn=1;
   while(t--){
      scanf("%d %d\n",&n,&k);
      vector<pair<int,int> >vd;
      for(int i=0;i<n;i++){
         scanf("%d %d\n",&x,&y);
         vd.push_back(make_pair(x,y));
      }
      vector<edge>ve;
      for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++){
            h=hypot(vd[i].first-vd[j].first,vd[i].second-vd[j].second);
            edge ed(i,j,h);
            ve.push_back(ed);
         }
     for(int i=0;i<MAX;i++)MAKE(i);
     sort(ve.begin(),ve.end(),orden);
     int nCu=0;
     double nCh=0,nTr=0,s;
     
     for(int i=0;i<ve.size();i++){
         if(FIND(ve[i].a)!=FIND(ve[i].b)){
            UNION(ve[i].a,ve[i].b);
            if(ve[i].w<=k)
               nCh+=ve[i].w;
            else{ 
               nTr+=ve[i].w;
               nCu++;
            }
         }
     }
     s=nCh+nTr;     
     int intr=round(nTr+1e-9);
     int inch=round(nCh+1e-9);
     nCu++;
     printf("Case #%d: %d %d %d\n",cn++,nCu,inch,intr);          
   }
   
   return 0;

}
