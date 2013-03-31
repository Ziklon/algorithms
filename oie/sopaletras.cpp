#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int f,c;
	while(cin>>f>>c){
		char m[f+4][c+4];
		memset(m,'.',sizeof(m));
		for(int i=2;i<f+2;i++){
			for(int j=2;j<c+2;j++){
				 cin>>m[i][j];
			}
		}
      for(int i=2;i<f+2;i++){
			for(int j=2;j<c+2;j++){
				 for(int x=i-2;x<=x+2;x+=2){
				 	for(int y=i-1;)	
				 }
			}
		}
				
	}	
}
