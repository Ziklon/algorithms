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
 int N,A,B,X,Y;
 bool G[101][101];
 bool visit[101][101];
 
void dfs(int x, int y){
	visit[x][y]=1;
	visit[y][x]=1;
	for(int i=1;i<=A;i++){		
		if(G[i][y]==1 && !visit[i][y])
			dfs(i,y);
		if(G[x][i]==1 && !visit[x][i])
			dfs(x,i);
	}	
} 
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  cin>>N;
  
  while(N--){
  	cin>>A>>B;
  	memset(G,0,sizeof(G));
  	memset(visit,0,sizeof(visit));
	for(int i=0;i<B;i++){
		cin>>X>>Y;
		G[X][Y]=1;
		G[Y][X]=1;
	}
	int dev=0;
	for(int i=1;i<=A;i++)
		for(int j=1;j<=A;j++){
			if(G[i][j]==1 && !visit[i][j]){
				dev++;
				dfs(i,j);	
			}		
		}  	
	if(dev==0)dev=A;
	cout<<dev<<endl;
  }
  //system("pause");
  return 0;
}
