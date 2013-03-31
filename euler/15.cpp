#include <iostream>
#include <cmath>

using namespace std;

int go(int x, int y){
	if(x<0 || y<0)return 0;
	if(x==0 && y==0)return 1;
	return (go(x-1,y)+go(x,y-1))-1;
}

int main(){
	cout<<go(2,2)<<endl;
}
