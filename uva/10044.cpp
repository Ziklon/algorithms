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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int T,N,P;
map<string,int>M;
vector<int> G[5000];
bool vis[5000];

int D[5000];
string line;
int root;
int sink;
string trim(string s){
	int i=0;
	int j=s.sz-1;
	while(i<s.sz && s[i]==' ')i++;
	while(j>=0 && s[j]==' ')j--;
	return s.substr(i,j-i+1);
}

void parse(string s){	
	int ubi=s.find(':');
	s=s.substr(0,ubi)+",";
	vector<string> v;
	int cnt=0;
	ubi=0;
	REP(i,0,s.sz){
		if(s[i]==',')cnt++;
		if(cnt==2){
			v.push_back(trim(s.substr(ubi,i-ubi)));
			ubi=i+1;
			cnt=0;
		}
	}
	REP(i,0,v.sz)if(M[v[i]]==0){
		M[v[i]]=M.sz+1;
	}
	REP(i,0,v.sz)REP(j,i+1,v.sz){		
		int p=M[v[i]];
		int q=M[v[j]];
		if(v[i]=="Erdos, P.")root=p;
		if(v[j]=="Erdos, P.")root=q;
		G[p].push_back(q);
		G[q].push_back(p);
	}
	
}
void solve(){
	scanf("%d\n",&T);
	REP(t,0,T){
		scanf("%d %d\n",&N,&P);
		M.clear();
		REP(i,0,5000){
			G[i].clear();
			D[i]=INF;
			vis[i]=0;
		}
		REP(i,0,N){
			getline(cin,line);
			parse(line);
		}
		queue<int>Q;
		Q.push(root);
		vis[root]=1;
		D[root]=0;
		while(!Q.empty()){
			int cur=Q.front();Q.pop();
			REP(i,0,G[cur].sz){
				if(!vis[G[cur][i]]){
					D[G[cur][i]]=D[cur]+1;
					vis[G[cur][i]]=1;
					Q.push(G[cur][i]);	
				}		
			}		
		}
		printf("Scenario %d\n",t+1);
		REP(i,0,P){
			getline(cin,line);
			line=trim(line);
			sink=M[line];
			if(D[sink]==INF){
				printf("%s infinity\n",line.c_str());
			}else{
				printf("%s %d\n",line.c_str(),D[sink]);			
			}		
		}
	}	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

