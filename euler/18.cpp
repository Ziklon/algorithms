#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int dat[2000][2000];
long long dp[200][200];
long long go(int x, int y){
	if(x>=100)return 0;
	long long& ref=dp[x][y];
	if(ref!=-1)return ref;
	ref=dat[x][y]+ max(go(x+1,y),go(x+1,y+1));
	return ref;
}
int main(){
  freopen("triangle.txt","r",stdin);
  freopen("out.txt","w",stdout);
  for(int i=0;i<100;i++)
  	for(int j=0;j<=i;j++)
  		cin>>dat[i][j];
  memset(dp,-1,sizeof dp);
  cout<<go(0,0)<<endl;
  system("pause");
  return 0;
}
