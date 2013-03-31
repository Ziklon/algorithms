#include <iostream>
#define LIMIT 5842
using namespace std;
int N,R;
int prime[4]={2,3,5,7};


int main(){
	N=21;
	dfs(0,0);
	cout<<R<<endl;
	return 0;
}
