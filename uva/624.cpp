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
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
string line;
int N,T,tacks[30],dp[22][5000],path[22][5000];

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(getline(cin,line)){
		istringstream is(line);
		is>>N>>T;
		REP(j,0,T)is>>tacks[j];
		fill(path,-1);
		fill(dp,0);
		for(int i=1;i<=T;i++){
			for(int j=1;j<=N;j++){
				dp[i][j]=dp[i-1][j];
				path[i][j]=1;
				if(j>=tacks[i-1] && dp[i-1][j-tacks[i-1]]+tacks[i-1]>dp[i][j]){
					dp[i][j]=max(dp[i][j],dp[i-1][j-tacks[i-1]]+tacks[i-1]);
					path[i][j]=2;
				}
			}
		}
		int ans=dp[T][N];
		int M=N;
		int R=T;
		vector<int> res;
		while(R>=1 && path[R][M]!=-1){
			if(path[R][M]==2){
				res.push_back(tacks[R-1]);				
				M-=tacks[R-1];
				//R-=1;
			}
			R-=1;		
		}
		for(int i=res.sz-1;i>=0;i--)cout<<res[i]<<" ";
		
		cout<<"sum:"<<ans<<endl;
		
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
