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
#define oo 1<<30
#define MID 1000000
using namespace std;

int t,n,m,p,num=1;
string line;
int M[1000020];


void solve(){
	while(scanf("%d",&t)==1 && t){
		queue<int> P[t+5];
		fill(M,0);
		vector<int> vis(t+5,0);
		vector<int> v;
		REP(i,0,t){
			scanf("%d",&n);
			REP(j,0,n){
				scanf("%d",&m);
				M[m]=i+1;
			}
			scanf("\n");
		}
		scanf("\n");
		printf("Scenario #%d\n",num++);
		while(getline(cin,line)){
			if(line=="STOP")break;
			if(line=="DEQUEUE"){
				if(v.sz>0){
					p=v[0];					
					vis[p]--;
					printf("%d\n",P[p].front());
					P[p].pop();
					if(vis[p]==0)
						v.erase(v.begin());
				}
			}else{
				sscanf(line.c_str(),"ENQUEUE %d",&m);
				p=M[m];
				if(!vis[p])v.push_back(p);					
				vis[p]++;
				P[p].push(m);				
			}				
		}
		printf("\n");
		
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

