#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int N;
char buff[50];
string v[100005];
int j,ans,i,M;
int main(){
	
	//freopen("D:/input.txt","r",stdin);
	while(scanf("%d\n",&N)==1){
		for(i=0;i<N;i++){
			scanf("%s\n",buff);
			v[i]=buff;
		}
		sort(v,v+N);
		ans=0;
		M=v[0].size();
		for(i=1;i<N;i++){
			j=0;				
			while(j<M && v[i][j]==v[i-1][j])j++;			
			ans=max(ans,j);		
		}
		printf("%d\n",ans);		
	}
	return 0;
}

