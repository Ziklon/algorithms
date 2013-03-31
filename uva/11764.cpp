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
  int n,m;
  int dat[55];
  cin>>n;
  for(int j=1;j<=n;j++){
      cin>>m;
      
      for(int i=0;i<m;i++)cin>>dat[i];  
      int low=0,higth=0;    
      for(int i=1;i<m;i++)
         if(dat[i]>dat[i-1])
            higth++;
         else if(dat[i]<dat[i-1])
               low++;         
      printf("Case %d: %d %d\n",j,higth,low);
  }
  return 0;
}
