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

bool orden(pair<string,int>p , pair<string,int>q){
   return p.second<q.second;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int T,val;
  string name;
  cin>>T;
  for(int i=0;i<T;i++){
      vector<pair<string,int> >vp;
      for(int j=0;j<4;j++){
         cin>>name>>val;
         vp.push_back(make_pair(name,val));
      }
      sort(all(vp),orden);
      cout<<"Poor "<<vp[0].first<<endl;
  }
  return 0;
}
