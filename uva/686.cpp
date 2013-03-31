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

bool S[50000];
int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	fill(S,0);
	for(int i=2;i*i<=40000;i++)
		if(!S[i])
			for(int j=i*i;j<=40000;j+=i)
				S[j]=1;
	vector<int>P;
	REP(i,2,35000)if(!S[i])P.push_back(i);
	int N,ans,X;
	while(scanf("%d",&N)==1 && N){
		set<int>S;
		for(int i=0;i<P.sz;i++){
			X=N-P[i];
			if(X<0)break;
			if(binary_search(all(P),X)){
				S.insert(min(X,P[i]));
			}
		}
		printf("%d\n",S.sz);
	
	}
	
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
