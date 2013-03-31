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
bool data[110][110];
bool visit[110];
int dp[110][110];
int N,K,A,P,aux;
int dfs(int x){
	visit[x]=1;
	int dev=0;
	for(int i=1;i<=N;i++){
		if(data[x][i]==1 && !visit[i])
			dev+=1+dfs(i);	
	}
	return dev;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  
  while(cin>>N){
  	if(N==0)break;
  	memset(data,0,sizeof(data));
	memset(dp,-1,sizeof(dp));  	
  	int dev=0,mx=0;
  	for(int i=0;i<N;i++){
		cin>>K;
		for(int j=0;j<K;j++){
			cin>>A;
			data[i+1][A]=1;
		}
	}
	for(int i=1;i<=N;i++){		
		memset(visit,0,sizeof(visit));
		aux=dfs(i);
		if(aux>mx){
			mx=aux;
			dev=i;
		}
	}
	cout<<dev<<endl;
  	
  }
  //system("pause");
  return 0;
}
