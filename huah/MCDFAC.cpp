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
#define INF 1<<30
using namespace std;
long long A,B,C,D,P,Z;

vector<pair<long long,int> >get(long long n){
	vector<pair<long long,int> >v;
	for(long long i=2;i*i<=n;i++){
		int cnt=0;
		while(n%i==0){
			n/=i;
			cnt++;
		}
		if(cnt>0)v.push_back(make_pair(i,cnt));
	}
	if(n>1)v.push_back(make_pair(n,1));
	return v;
}


void solve(){
	int N;
	scanf("%d\n",&N);
	REP(t,0,N){
		scanf("%lld %dll",&A,&B);
		C=1;
		vector<pair<long long,int> >v=get(B);		
		REP(i,0,v.sz){
			D=1;
			int prev=0;
			int acu=0;
			P=0;
			while(D<A){			
				D*=v[i].first;
				if(D<=A)acu++;
				Z=1;
				REP(j,0,acu){
					Z*=v[i].first;
					if(A<D)prev+=(max(min(A,D)-P,1LL))/Z;
					else prev+=(max(min(A,D)-P-1,1LL))/Z;
				}
				P=D;	
			}
			acu=(acu*(acu+1))/2;
			int res=min(prev+acu,v[i].second);		
			
			REP(j,0,res)C*=v[i].first;		
		}
		
		printf("Caso #%d: %lld\n",t+1,C);
		
	}
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		freopen("D:/output.txt","w",stdout);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

