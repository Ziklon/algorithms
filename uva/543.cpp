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
#define MAX 1000000
using namespace std;
bool S[MAX +2];

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	fill(S,0);
	for(int i=2;i*i<=MAX;i++)
		if(!S[i])
		for(int j=i*i;j<=MAX;j+=i)
			S[j]=1;
	vector<int>P;
	REP(i,3,MAX)if(!S[i])P.push_back(i);
	int N,X,R;
	while(scanf("%d",&N)==1 && N){
		X=-1;	
		REP(i,0,P.sz){
			R=N-P[i];
			if(R<0)break;
			if(binary_search(all(P),R)){
				X=P[i];
				break;
			}
		}
		if(X>0)printf("%d = %d + %d\n",N,X,N-X);
		else printf("Goldbach's conjecture is wrong.");
	
	}
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
