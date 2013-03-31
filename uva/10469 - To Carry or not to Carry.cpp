#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long ll;

unsigned int a,b,c;
int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);
	while(scanf("%u %u",&a,&b)==2){
		c=a^b;
		printf("%u\n",c);
	}
	return 0;
}

