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
typedef long long ll;

string S[40];
int N,Q;

ll A[40],tmp,B[40],m,expo;



int get(ll num, int pos, int nd){
	int R=nd-1;
	while(num){
		num--;
		if(num==0)break;
		if(pos==R)return num%N;
		num/=N;
		R--;	
	}
	return 0;
}

void solve(){
		

	while(cin>>N>>Q){
		if(N==0 && Q==0)break;
		A[1]=1;	
		A[0]=0;
		B[1]=1;
		expo=N;
		REP(i,2,40){
			tmp=expo*(i-1);    
			A[i]=A[i-1]+(tmp/(i-1));
			B[i]=B[i-1]+tmp;
			expo*=N;
			if(expo<0)break;
		}
		REP(i,0,N)cin>>S[i];		
		
		REP(i,0,Q){
			cin>>m;
			int nd=1;
			while(B[nd+1]<=m)nd++;	
			ll pos=(m-B[nd])/nd;
			ll ubi=(A[nd]+pos);
			pos=(m-B[nd])%nd;
			nd=get(ubi,(int)pos,nd);
			printf("%s\n",S[nd].c_str());
		}				
		printf("\n");
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


