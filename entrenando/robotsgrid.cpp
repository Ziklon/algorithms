#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll MOD = (1LL<<31)-1;
ll dp[1000][1000];
char M[1000][1000];
int N;

int dx[]={0,-1};
int dy[]={-1,0};

int main(){
	scanf("%d\n",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			scanf("%c",&M[i][j]),dp[i][j]=0;
		scanf("\n");
	}
	
	dp[0][0]=1;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(M[i][j]=='#')continue;
			for(int k=0;k<2;k++){
				int x=i+dx[k];
				int y=j+dy[k];
				if(min(x,y)>=0){
					dp[i][j]=(dp[i][j]+dp[x][y])%MOD;
				}
			}					
		}
	}
	
	if(dp[N-1][N-1]==0)
		cout<<"THE GAME IS A LIE"<<endl;
	else
		cout<<dp[N-1][N-1]<<endl;
	return 0;
}
