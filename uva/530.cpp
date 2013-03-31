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

long long combi(long long a, long long b){
   long long c=a-b,ans=1,y=2;
   if(c>b)swap(b,c);
   vector<long long> divs;
   set<long long> vis;
   while(y<=c)divs.push_back(y++);
   for(long long j=b+1;j<=a;j++){
      ans*=j;
      rep:
      for(int i=0;i<divs.sz && ans>1;i++){
         if(vis.count(divs[i])==0 && ans%divs[i]==0){
            vis.insert(divs[i]);
            ans/=divs[i];
            goto rep;
         }
      }   
   }
   node:
   for(int j=0;j<divs.sz && ans>1;j++){
      if(vis.count(divs[j])==0 && ans%divs[j]==0){
         vis.insert(divs[j]);
         ans/=divs[j];
         goto node;
      }
   }  
   return ans;
   
}

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   long long a,b;
   while(cin>>a >> b && a&&b){      
      cout<<combi(a,b)<<endl;
   }
   return 0;
}
