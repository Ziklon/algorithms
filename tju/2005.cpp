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
int T[1005][1005],R,C,N,x,y;
int di[]={0,0,1,-1,1,-1,1,-1,2,1,-1,-2,-1,-2,1,2};
int dj[]={1,-1,0,0,1,-1,-1,1,1,2,-2,-1,2,1,-2,-1};

void dfs(int x, int y, int d){
	if(x<1 || y<1 || x>R || y>C )return;
	if(T[x][y]!=0 && T[x][y]!=5)return;
	T[x][y]=5;
	dfs(x+di[d],y+dj[d],d);
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//1 Queen
	//2 Knight
	//3 Pawn
	int Tc=1;
	while(scanf("%d %d",&R,&C)==2){
		if(R==0 && C==0)break;
		fill(T,0);
		REP(j,1,4){
			scanf("%d",&N);
			REP(k,0,N){
				scanf("%d %d",&x,&y);
				T[x][y]=j;
			}
		}
		REP(i,1,R+1)
			REP(j,1,C+1){
				int X,Y;
				switch(T[i][j]){
					case 1:
						for(int k=0;k<8;k++){
							X=i+di[k];
							Y=j+dj[k];
							dfs(X,Y,k);
						}
						break;
					case 2:
						for(int k=8;k<16;k++){
							X=i+di[k];
							Y=j+dj[k];
							if(X<1 || Y<1 || X>R || Y>C || T[X][Y]!=0)continue;
							T[X][Y]=5;							
						}
						break;
					
				}
			}
		int peki=0;
		REP(i,1,R+1)
			REP(j,1,C+1){
				if(T[i][j]==0){
					//cout<<i<<" "<<j<<endl;
					peki++;
				}
			}
		printf("Board %d has %d safe squares.\n",Tc++,peki);
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
