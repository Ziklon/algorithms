#include <vector>
#include <map>
#include <set>
#include <iomanip>
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
#define oo 1<<30
using namespace std;



const int TAM=1000003;
int S[TAM],N,R;
vector<int>P;
long long num,Z[TAM];
void solve(){
	fill(S,0);
	for(int i=2;i*i<TAM;i++)
		if(!S[i])
			for(int j=i*i;j<TAM;j+=i)
				S[j]=1;
	
	
	REP(i,2,TAM)if(!S[i])P.push_back(i);
	
	REP(i,0,P.sz){
		S[P[i]]=P[i];
		for(num=P[i]*1LL*P[i];num<=1000000LL;num*=P[i])
			S[(int)num]=P[i];
	}
	
	int MOD=10000000;
	Z[1]=1;

	for(int i=2;i<TAM;i++){
		if(S[i]==2||S[i]==5){			
			Z[i]=(Z[i-1]*S[i]);
			while(Z[i]%10==0)Z[i]/=10;
			Z[i]=Z[i]%MOD;			
		}
		else{
			Z[i]=(Z[i-1]*S[i])%MOD;	
		}
	}	
	while(scanf("%d",&N)==1 && N){		
		printf("%d\n",Z[N]%10);
		
	}
	
    	
    
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

