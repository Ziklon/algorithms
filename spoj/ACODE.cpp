#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef unsigned long long ll;
string line;
ll dp[5005];

int ways(int& i, string& s){
	if(i+1==s.sz)return 1;
	int m=((s[i]-'0')*10)+(s[i+1]-'0');
	if(m==20 || m<=10)return 1;
	if(m<=26)return 2;
	return 1;
}



void solve(){
	while(getline(cin,line)){
		if(line=="0")break;
		dp[line.sz]=1;
		for(int i=line.sz-1;i>=0;i--){
			dp[i]=dp[i+1];
			if(ways(i,line)==2 && line[i+2]!='0'){
				dp[i]+=dp[i+2];
			}
		}		
		cout<<dp[0]<<endl;
	}
	
}
int main(){
	#ifdef LocalHost
		freopen("E:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

