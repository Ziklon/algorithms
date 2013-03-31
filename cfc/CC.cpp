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
vector<int> G[101];
bool vis[101];
int v,e,x,y;
bool dfs(int x){
   vis[x]=1; 
   bool ans=0;   
   for(int i=0;i<G[x].sz;i++){
      if(!vis[G[x][i]])
         dfs(G[x][i]);
      else
         ans=1;
   }
   return ans;
}
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   
   cin>>v>>e;
   fill(G,0);
   fill(vis,0);
   for(int i=0;i<e;i++){
      cin>>x>>y;
      G[x].push_back(y);
      G[y].push_back(x);
   }
   bool ans=0;
   for(int i=0;i<v;i++){
      if(!vis[i])
         ans|=dfs(i);
   }
   if(ans)
      cout<<"FHTAGN!"<<endl;
   else
      cout<<"NO"<<endl;
   //system("pause");
   return 0;
}
