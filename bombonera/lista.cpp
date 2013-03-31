#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char buff[50];
vector<string>v;
int j,ans,i,M,N,k;
int main(){
	
	//freopen("D:/input.txt","r",stdin);
	while(scanf("%d\n",&N)==1){
		v.resize(N);
		for(i=0;i<N;i++){
			scanf("%s\n",buff);
			v[i]=buff;
		}
		sort(v.begin(),v.end());
		ans=0;
		M=v[0].size();
		for(i=1;i<N;i++){
			j=0;
			k=i-1;	
			while(j<M && v[i][j]==v[k][j]){
				j++;
			}
			ans+=j;		
		}
		printf("%d\n",ans);		
	}
	return 0;
}

