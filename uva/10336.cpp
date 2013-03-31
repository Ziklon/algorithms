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
string data[150];
bool visit[150][150];
int nC,H,W,C;
int di[8]={0,0,1,-1,1,-1,1,-1};
int dj[8]={1,-1,0,0,1,-1,-1,1};

void dfs(int x, int y, char c){
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		int X=di[i]+x;
		int Y=dj[i]+y;
		if(X>=0 && X<H && Y>=0 && Y<W && data[X][Y]==c && !visit[X][Y])
			dfs(X,Y,c);
	}	
}
bool orden(pair<char,int>p, pair<char,int> q){
	if(p.second!=q.second)
		return p.second>q.second;
	return p.first<q.first;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  scanf("%d\n",&nC);
  C=1;
  while(nC--){
	memset(visit,0,sizeof visit);
  	scanf("%d %d\n",&H,&W);
  	map<char,int> M;
  	char line[W+2];
  	for(int i=0;i<H;i++){
		scanf("%s\n",line);
		data[i]=line;
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(!visit[i][j]){
				M[data[i][j]]++;
				dfs(i,j,data[i][j]);
			}
		}
	}
	vector<pair<char,int> >v(all(M));
	sort(all(v),orden);
	printf("World #%d\n",C++);
	for(int i=0;i<v.sz;i++)
		printf("%c: %d\n",v[i].first,v[i].second);
	
  }
  //system("pause");
  return 0;
}
