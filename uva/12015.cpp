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

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,val,mx;
  string url;
  cin>>n;
  string urls[12];
  int vals[12];
  for(int j=1;j<=n;j++){
      mx=0;
      for(int i=0;i<10;i++){
         cin>>url>>val;
         urls[i]=url;
         vals[i]=val;
         mx=max(mx,val);
      }
      printf("Case #%d:\n",j);
      for(int i=0;i<10;i++)
         if(vals[i]==mx)
            printf("%s\n",urls[i].c_str());
      
  }
  return 0;
}
