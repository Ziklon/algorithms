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
int a,b,c,S,ans;
struct node{
	int x,y,d;
	node(int _x,int _y, int _d){
		x=_x;
		y=_y;
		d=_d;
	}
};
bool vis[2001][2001];



void solve(){
	while(scanf("%d %d %d\n",&a,&b,&c)==3){	
		if(a==b && b==c && c==0)break;
		fill(vis,0);
		ans=0;
		S=a+b+c;
		queue<node> Q;
		Q.push(node(a,b,0));
		vis[a][b]=1;
		while(!Q.empty()){
			node cur=Q.front();Q.pop();
			int A[3]={cur.x,cur.y,S-(cur.x+cur.y)};			
			bool ok=0;
			for(int i=0;i<3;i++)if(A[i]==0)ok=1;
			
			if(ok){
				ans=cur.d;
				break;
			}
			for(int i=0;i<3;i++)for(int j=0;j<3;j++)
				if(i!=j && A[i]>=A[j]){
					int B[3]={A[0],A[1],A[2]};
					B[i]=A[i]-A[j];
					B[j]=A[j]*2;
					if(!vis[B[0]][B[1]]){
						Q.push(node(B[0],B[1],cur.d+1));
						vis[B[0]][B[1]]=1;
					}
				
			}
				
		}
		printf("%d %d %d %d\n",a,b,c,ans);
	}

}
int main(){

	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

