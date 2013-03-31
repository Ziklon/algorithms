#include <iostream>
#include <cstring>

using namespace std;
int n=5,M=27;
int a[5]={1,3,5,8,10};
int m[37];

int main(){
	memset(m,0,sizeof(m));
	m[0]=1;
	for(int i=0;i<n;i++)
		for(int j=36;j>=a[i];j--){
			//cout<<j<<endl;
			m[j]=m[j]|m[j-a[i]];
		}
	
	for(int i=0;i<37;i++)
		cout<<i<<" "<<m[i]<<endl;   	

	system("pause");
	return 0;
}
