#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int N,D;
	while(cin>>N>>D){
		if(N==0&&D==0)break;
		int board[D][N];
		for(int i=0;i<D;i++)
			for(int j=0;j<N;j++)
				scanf("%d",&board[i][j]);
		bool ok=0;
		for(int j=0;j<N &&!ok;j++){
			bool d=1;
			for(int i=0;i<D ;i++)
				d&=board[i][j]==1;
			ok=d;
		}				
		if(ok)printf("yes\n");
		else printf("no\n");	
	}
	return 0;

}
