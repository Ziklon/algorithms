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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
#define MAX 100006
int P[MAX];
int find(int n){
   if(P[n]==n)return n;   
   P[n]=find(P[n]);
   return P[n];
}
void UNION(int p, int q){
   P[find(p)] =find(q);  
}
bool inter(int x, int y){
   int cn=0;
   while(x!=y && cn<2){
      x=P[x];
      cn++;
   }
   return x==y;
}
int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   //793
   int t,x,y,n,a,b;
   char cur[3];
   scanf("%d\n",&t);
   //getline(cin,line);
   for(int i=0;i<t;i++){
      if(i>0)printf("\n");
      scanf("%d\n",&n);      
      for(int j=0;j<=n+5;j++)P[j]=j;
      a=0;
      b=0;
      while(scanf("%s %d %d\n",cur,&x,&y)==3){
         switch(cur[0]){
            case 'c': UNION(x,y);
                       break;
            case 'q': if(find(x)==find(y)){
                        if(inter(x,y)|| inter(y,x))a++;
                        else b++;
                     }else b++;
                      break;   
         }
      }
      printf("%d,%d\n",a,b);
   }
   return 0;
}
