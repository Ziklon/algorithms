#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int coins[5]={6,4,1,10,20};
int dp[6][1000];

int go(int p, int c){
	if(p>=5)return 1<<30;
	if(c<0)return 1<<30;
	if(c==0)return 0;
	int dev=1<<30;
	dev=min(dev,min( 1+ go(p,c-coins[p]), go(p+1,c)));
	return dev;
}


int main(){	
	cout<<go(0,8)<<endl;
	return 0;
}
