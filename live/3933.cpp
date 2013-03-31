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
int R,C;
char M[101][101];
int  G[101][101],xs,ys,x,y,d;

const int dx[6] = { -1, -1, 0, 0, 1, 1 };
const int dy[6] = { 0, 1, -1, 1, -1, 0 };

int main(){

	
	while(scanf("%d %d\n",&R,&C)==2){
		if(R==0 && C==0)break;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				scanf("%c",&M[i][j]);
				G[i][j]=0;
			}
			scanf("\n");
		}
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(M[i][j]=='I'){					
					queue<int> Q;
					G[i][j]|=1;
					Q.push(i);Q.push(j);Q.push(0);					
					while(!Q.empty()){
						x=Q.front();Q.pop();y=Q.front();Q.pop();
						d=(Q.front()+1)%2;Q.pop();						
						for(int k=0;k<6;k++){
							int X=x+dx[k];
							int Y=y+dy[k];
							if(min(X,Y)>=0 && X<R && Y<C && M[X][Y]!='.'){
								if((G[X][Y]&(1<<d))==0){
									G[X][Y]|=(1<<d);
									Q.push(X);Q.push(Y);Q.push(d);
								}
							}	
						}					
					}
				
				}
			}
		}
		printf("\n");
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(M[i][j]=='.')printf(".");
				else if(G[i][j]==0) printf("F");
				else if(G[i][j]==1)printf("(");
				else if(G[i][j]==2)printf(")");
				else printf("B");
			}
			printf("\n");
		}		
		
	}	
	return 0;
}
