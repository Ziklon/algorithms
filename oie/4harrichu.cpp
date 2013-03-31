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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
bool vis[50][55];
string mapa[50];
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
int F,C;
int dfs(int x, int y){
	vis[x][y]=1;
	int ans=0;
	REP(i,0,4){
		int X=x+di[i];
		int Y=y+dj[i];
		//se verique que X and Y este dentro del cuadro
		// que no sea un obstaculo
		// y q no lo haya visitado
		if(X>=0 && Y>=0 && X<F && Y<C && mapa[X][Y]!='#' && !vis[X][Y]){
			if(mapa[X][Y]>'Z' || mapa[X][Y]<'A'){
				if(mapa[X][Y]=='g')ans=1;
				ans=max(ans,dfs(X,Y));
			}
		}
	}
	return ans;
}

int main(){
	freopen("in.txt","r",stdin);
	int K;
	scanf("%d\n",&K);
	char buff[55];
	
	REP(k,0,K){
		scanf("%d %d\n",&F,&C);
		REP(i,0,F){
			scanf("%s\n",buff);		
			mapa[i]=buff;
			//cout<<mapa[i]<<endl;
		}
		fill(vis,0);//limpio los visitados
		int xs,ys;//buscar 
		
		REP(i,0,F)REP(j,0,C)if(mapa[i][j]=='b'){
			xs=i;
			ys=j;
		}
		int ans=dfs(xs,ys);
		if(ans)cout<<"Good"<<endl;
		else cout<<"Bad"<<endl;
	}
 	
	
   
	return 0;
}

