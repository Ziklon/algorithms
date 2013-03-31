#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int B[3][3];
int main(){
	ios::sync_with_stdio(false);
	
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>B[i][j];
	
	int C[3]={};

	for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(i!=j)C[i]+=B[i][j];
	
	int mx=max(C[0],max(C[1],C[2]));
	
	for(int i=0;i<3;i++)B[i][i]=mx-C[i];
	int sumaa=(B[0][1]+B[0][2]-B[1][1]-B[2][2])/2;
	
	B[1][1]+=sumaa;
	B[2][2]+=sumaa;
	sumaa=0;
	for(int i=0;i<3;i++)sumaa+=B[i][1];
	B[0][0]=sumaa-B[0][1]-B[0][2];
	
	for(int i=0;i<3;i++){
		cout<<B[i][0];
		for(int j=1;j<3;j++)
			cout<<" "<<B[i][j];
		cout<<endl;
	}					
	return 0;
}
