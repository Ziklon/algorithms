#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int n,m,dat[81];
char enc[82];
int main(){
	while((scanf("%d %d\n",&n,&m))==2){
		if(n==0&&m==0)break;
		for(int i=0;i<n;i++)
			scanf("%d ",&dat[i]);		
		scanf("\n%s\n",enc);
		m=m%n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				for(int x=j+1;x<n;x++)
					swap(enc[dat[j]-1],enc[dat[x]-1]);
		}
		printf("%s\n",enc);
	}
	return 0;
}
