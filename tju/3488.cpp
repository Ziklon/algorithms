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

int search(vector<long long>& v, long long num){
   int low=0;
   int hig=v.sz-1;
   while(low<=hig){
      int med=(low+hig)/2;
      if(v[med]==num)return med;
      else if(v[med]>num)
         hig=med-1;
      else
         low=med+1;
   }
   return -1;
}

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t,n,y;
   long long xx,ans;
   scanf("%d",&t);
   for(int i=0;i<t;i++){
      scanf("%d",&n);
      vector<long long> v(n+1,0);
      ans=0;
      for(int j=1;j<=n;j++){
         scanf("%d",&y);
         v[j]=v[j-1]+y;
      }
      for(int j=0;j<v.sz;j++){
         xx=v[j]-47;
         if(search(v,xx)!=-1)ans++;
      }
      printf("%d\n",ans);
      
   }
   return 0;
}
