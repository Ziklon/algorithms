#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
using namespace std;
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define sz size()

long long dp[309][1005];
int main(){
	freopen("in.txt","r",stdin);
	string line;
	fill(dp,0);
	REP(i,1,309)dp[i][1]=1;
	REP(i,1,309)dp[i][i]=1;
	
	REP(i,1,309){
		REP(j,i,309){
			REP(k,1,309)
				dp[j][k]+=dp[j-i][k-1];
			
		}
	}
	int peki=0;
	REP(i,1,7){
		//cout<<dp[6][i]<<endl;
		peki+=dp[6][i];
	}
	cout<<dp[6][6]<<endl;
	
	// while(getline(cin,line)){
		// istringstream is(line);
		// vector<int> v;
		// int val;
		// while(is>>val)v.push_back(val);
		
		
		
	// }
	return 0;

}