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
string s,u;
int i,j;
int dp[2005][2005];


int go(int x, int y){
	if(x>=s.sz || y>=u.sz)return 0;
	int& ref=dp[x][y];
	if(ref!=-1)return ref;
	

}



int main(){
    clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	cin>>s>>u;
	fill(dp,-1);
	
	fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
	
}
