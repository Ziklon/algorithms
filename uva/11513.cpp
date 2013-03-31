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
typedef vector<int> vi;
vi v(9);
vi tmp(9);
int B[3];
map<vi,string>M;
string ans;
void solve(){
	REP(i,0,9)v[i]=i+1;
	queue<vi>Q;
	Q.push(v);
	map<vi,bool> vis;
	vis[v]=1;
	M[v]="";
	while(!Q.empty()){
		tmp=Q.front();Q.pop();
		ans=M[tmp];
		v=tmp;
		for(int i=0;i<9;i+=3){
			REP(j,0,3)B[j]=v[i+j];			
			REP(j,0,3)v[i+j]=B[(j+1)%3];			
			if(vis[v]==0){
				Q.push(v);
				M[v]="H"+string(1,'1'+(i/3))+ans;
				vis[v]=1;
			}			
			REP(j,0,3)v[i+j]=B[j];				
		}
		REP(j,0,3){
			for(int i=0;i<9;i+=3)B[i/3]=v[i+j];				
			for(int i=0;i<9;i+=3)v[i+j]=B[((i/3)+2)%3];				
			if(vis[v]==0){
				Q.push(v);
				M[v]="V"+string(1,'1'+j)+ans;
				vis[v]=1;
			}			
			for(int i=0;i<9;i+=3)v[i+j]=B[i/3];
		}
		
	}
	while(1){
		REP(i,0,9){
			scanf("%d",&v[i]);
			if(v[i]==0)return;
		}
		if(vis[v]==1){
			ans=M[v];
			printf("%d %s\n",ans.sz/2,ans.c_str());
		}else{
			printf("Not solvable\n");
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

