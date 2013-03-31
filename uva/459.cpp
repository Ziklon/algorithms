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
bool G[27][27];
bool visit[27][27];
int N,nC;
string L;
char M='A';
void dfs(int x, int y){
	visit[x][y]=1;
	visit[y][x]=1;	
	for(int i=0;i<=M-'A';i++){
		if(G[x][i]==1 && !visit[x][i])
			dfs(x,i);
		if(G[i][y]==1 && !visit[i][y])
			dfs(i,y);
	}
			
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  scanf("%d\n",&N);
  while(N--){
  	memset(visit,0,sizeof visit);
  	memset(G,0,sizeof(G));
  	getline(cin,L);
  	//getline(cin,L);
  	M=L[0];
  	while(getline(cin,L)){
		if(L=="")break;
		G[L[0]-'A'][L[1]-'A']=1;
		G[L[1]-'A'][L[0]-'A']=1;
	}
	int dev=0;
	for(int i=0;i<=M-'A';i++){
		bool ok=1;
		for(int j=0;j<=M-'A';j++)
			if(G[i][j]){
				ok=0;
				if(!visit[i][j]){
					dfs(i,j);
					dev++;	
				}				
			}
		dev+=ok;
		
	}
	cout<<dev<<endl;
	if(N)
		cout<<endl;	
	
  }
  //system("pause");
  return 0;
}
