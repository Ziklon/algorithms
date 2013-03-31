#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;

vector<int> G[2001];
int S[2001];
int N,x,y,T,M;
bool ok;
void dfs(int x, int tip){
	if(S[x]>=0){
		if(S[x]!=tip) ok=0;
		return;
	}	
	S[x]=tip;
	for(int i=0;i<G[x].sz;i++){
		dfs(G[x][i],tip^1);
	}	
	
}

int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N>>M;
		for(int i=1;i<=N;i++){
			S[i]=-1;
			G[i].clear();
		}
		for(int i=0;i<M;i++){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		ok=1;
		for(int i=1;i<=N;i++)if(S[i]==-1){
			dfs(i,1);
		}
		cout<<"Scenario #"<<t<<":"<<endl;
		if(ok)cout<<"No suspicious bugs found!"<<endl;
		else cout<<"Suspicious bugs found!"<<endl;
		
	}
	return 0;
}
