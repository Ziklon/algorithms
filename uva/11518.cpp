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
int t,n,m,l,dev,x,y;
vector<int> A[10005];
bool vis[10005];
set<int>S;
void dfs(int n){
   S.insert(n);
   vis[n]=1;
   for(int i=0;i<A[n].sz;i++)
      if(!vis[A[n][i]])
         dfs(A[n][i]);
}



int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  //11518
  cin>>t;
  while(t--){
      cin>>n>>m>>l;
      S.clear();
      for(int i=0;i<10005;i++)A[i].clear();
      for(int i=0;i<m;i++){
         cin>>x>>y;
         A[x].push_back(y);         
      }
      for(int i=0;i<l;i++){
         cin>>x;
         fill(vis,0);
         dfs(x);
      }
      cout<<S.sz<<endl;      
      
  }
  return 0;
}
