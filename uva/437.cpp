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

vector<int> C[33];
int N,T;
int dp[33][3][3];

int go(int index, int L, int A){
	int& ref=dp[index][L][A];
	if(ref!=-1)return ref;
	vector<int> v;
	REP(i,0,3)v.push_back(i);
	ref=0;
	REP(i,0,N){	
		do{
			if(C[index][L]>C[i][v[0]] && C[index][A]>C[i][v[1]])
				ref=max(ref,C[i][v[2]]+go(i,v[0],v[1]));
		}while(next_permutation(all(v)));		
	}	
	return ref;
}




int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	T=1;
	while(scanf("%d",&N)==1 && N){
		REP(i,0,N){
			C[i].resize(3);
			REP(j,0,3)scanf("%d",&C[i][j]);
			sort(all(C[i]));			
		}
		int ans=0;
		fill(dp,-1);
		REP(i,0,N){
			vector<int> v;
			REP(j,0,3)v.push_back(j);
			do{
				ans=max(ans,C[i][v[2]]+go(i,v[0],v[1]));
			}while(next_permutation(all(v)));
		}
		printf("Case %d: maximum height = %d\n",T++,ans);
		
	}
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
