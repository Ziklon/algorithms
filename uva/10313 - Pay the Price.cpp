#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#define INF 1<<20
using namespace std;
typedef long long ll;
string cad;
vector<int> coins;
vector<int> v;
int C=0;
int dp[305][1200];

int main(){
	ios::sync_with_stdio(false);
	while(getline(cin,cad)){
		istringstream is(cad);
		v.clear();
		int n;
		coins.clear();
		
		while(is>>n)v.push_back(n);	
		
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
				
		for(int i=1;i<=v[0];i++){			
			for(int j=0;j<=i;j++){
				for(int k=1;k<=i;k++){
					dp[i][j]=
				}	
			}
		
		}
		
				
		C=v.size();
		
		
		cout<<go(v[0],0)<<endl;	
					
	}
			
	return 0;
}
