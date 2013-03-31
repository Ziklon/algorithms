#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long dat[1001];
int N;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	dat[0]=1;
	dat[1]=1;
	for(int i=2;i<1001;i++)dat[i]=dat[i-1]+dat[i-2];
	while(cin>>N)
		cout<<dat[N-1]<<endl;
	return 0;
}
