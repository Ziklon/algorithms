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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
string adj[51];
int di[4]={1,-1,0,0},W,H,nC;
int dj[4]={0,0,1,-1};
bool visit[51][51];
int dfs(int x, int y, char c){
   visit[x][y]=1;
   int dev=1;
   for(int i=0;i<4;i++){
  	int X=di[i]+x;
  	int Y=dj[i]+y;
  	if(X>=0 && Y>=0 && X<W && Y<H && !visit[X][Y] && adj[X][Y]==c)
  		dev+=dfs(X,Y,c);
  }
  return dev;
}
bool orden(pair<char,int>p, pair<char,int>q){
	if(p.second!=q.second)
		return p.second>q.second;
	return p.first<q.first;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  nC=1;
  while(scanf("%d %d\n",&W,&H)==2){
  	if(W==0 && H==0)break;
  	char line[H+2];
  	memset(visit,0,sizeof(visit));
	for(int i=0;i<W;i++){
	   scanf("%s\n",line);
	   adj[i]=line;
	}
	vector<pair<char,int> >v;
	for(int i=0;i<W;i++)
		for(int j=0;j<H;j++)
			if(!visit[i][j] && isalpha(adj[i][j]))
				v.pb(mp(adj[i][j],dfs(i,j,adj[i][j])));
	sort(all(v),orden);
	printf("Problem %d:\n",nC++);
	for(int i=0;i<v.sz;i++)
		printf("%c %d\n",v[i].first,v[i].second);
  	
  }
  //system("pause");
  return 0;
}
