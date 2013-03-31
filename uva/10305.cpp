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
int degre[105],x,y,n,m;
vector<int> adj[105];

int main(){
   //freopen("D:/input.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   while(scanf("%d %d",&n,&m)==2 && (n)){
            
      for(int i=1;i<=n;i++){
		adj[i].clear();
		degre[i]=0;
	  }
	  vector<int>ans;	  
      for(int i=0;i<m;i++){
         scanf("%d %d",&x,&y);
         adj[x].push_back(y);
		 degre[y]++;
      }
	  queue<int>Q;
	  for(int i=1;i<=n;i++)if(degre[i]==0)Q.push(i);
	  while(!Q.empty()){
		int cur=Q.front();Q.pop();
		ans.push_back(cur);				
		for(int i=0;i<adj[cur].sz;i++){
			y=adj[cur][i];
			degre[y]--;
			if(degre[y]==0)Q.push(y);
					//cout<<"hey"<<endl;
	
		}
	  }
	  printf("%d",ans[0]);
	  for(int i=1;i<ans.sz;i++)printf(" %d",ans[i]);
	  printf("\n");
         
   }
   return 0;
}
