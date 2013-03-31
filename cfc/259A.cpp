#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

char B[8][8];
int main(){
	ios::sync_with_stdio(false);
	
	for(int i=0;i<8;i++)for(int j=0;j<8;j++)cin>>B[i][j];
	
	bool ok=1;
	
	for(int i=0;i<8;i++)for(int j=0;j<7;j++){
		if(B[i][j]==B[i][j+1])
			ok=0;
	}
	if(ok)puts("YES");
	else puts("NO");
				
	return 0;
}
