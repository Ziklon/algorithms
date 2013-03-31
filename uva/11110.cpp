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
int adj[105][105];
int di[4]={1,-1,0,0},N,nC,a,b;
int dj[4]={0,0,1,-1};
bool vis[105][105];

void dfs(int x, int y){
   vis[x][y]=1;
   for(int i=0;i<4;i++){
	int X=di[i]+x;
	int Y=dj[i]+y;
	if(X>=1 && Y>=1 && X<=N && Y<=N && adj[X][Y]==adj[x][y] && !vis[X][Y])
		dfs(X,Y);
  }
}
string line;
int main(){
  while(scanf("%d",&N)){
  	if(N==0)break;
  	memset(vis,0,sizeof(vis));
  	memset(adj,-1,sizeof(adj));
  	vector<int> liz(N+1,0);
  	getline(cin,line);
  	for(int i=1;i<N;i++){
		getline(cin,line);
		istringstream is(line);
		int a,b;
		while(is>>a>>b){
			if(adj[a][b]==-1)
			    liz[i]++;
			adj[a][b]=i;
		}
	}
	bool ok=1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		    if(adj[i][j]==-1){
		        adj[i][j]=N;
				liz[N]++;
			}

   for(int i=1;i+1<liz.sz;i++)
        if(liz[i]!=liz[i+1])
            ok=0;
	set<int>S;
	for(int i=1;i<=N && ok;i++){
    	for(int j=1;j<=N && ok;j++){
			if(!vis[i][j]){
				if(S.count(adj[i][j])>0)
				    ok=0;
				else{
					S.insert(adj[i][j]);
					dfs(i,j);
				}
			}
		}
	}
	if(ok)
		printf("good\n");
	else 
		printf("wrong\n");
	
  }
  //system("pause");
  return 0;
}
