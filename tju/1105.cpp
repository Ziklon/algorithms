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
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  string line;
  while(cin>>line){
      long long ans=26;
      queue<string>Q;
      bool ok=0;
      for(int i=0;i<26;i++)
         Q.push(string(1,'a'+i));
      
      while(!Q.empty() && line.sz>1){
         string cur=Q.front();
          Q.pop();
         if(cur.sz>5)break;        
         if(cur==line){
            ok=1;
            break;
         }
         int n=cur.sz;
         char c=cur[n-1]+1;
         for(;c<='z';c++){
            Q.push(cur+string(1,c));
            ans++;
         }   
      }
      if(line.sz==1){
         ans=line[0]-'a'+1;
         ok=1;
      }
      if(ok)cout<<ans<<endl;
      else cout<<0<<endl;   
  }
  return 0;
}
