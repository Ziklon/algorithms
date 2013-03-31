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
using namespace std;
int N,R,C;

int dp[101][101];
int table[101][101];
char buff[1024];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};



int go(int x, int y){
	int& ref=dp[x][y];
	if(ref!=-1)return ref;
	ref=1;
	REP(i,0,4){
		int X=x+dx[i];
		int Y=y+dy[i];
		if(min(X,Y)>=0 && X<R && Y<C && table[x][y]>table[X][Y]){
			ref=max(ref,go(X,Y)+1);
		}
	}
	return ref;

}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&N);
	REP(c,0,N){
		scanf("%s %d %d",buff,&R,&C);
		REP(i,0,R)
			REP(j,0,C)
				scanf("%d",&table[i][j]);
		
		fill(dp,-1);
		int peki=0;
		REP(i,0,R)
			REP(j,0,C)
				peki=max(peki,go(i,j));
		printf("%s: %d\n",buff,peki);
		
		
	
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
