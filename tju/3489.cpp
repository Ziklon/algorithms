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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define MOD 1000000007
using namespace std;
int M[55],N,K;
long long A;
int main(){
    //freopen("in.txt","r",stdin);
	scanf("%d",&K);
	REP(k,0,K){
		scanf("%d",&N);
		bool ok=1;
		REP(i,0,N){
			scanf("%d",&M[i]);
			
		}
		sort(M,M+N);
		A=M[0];
		REP(i,1,N)
			A=(A*(M[i]-i))%MOD;
		if(A>0)
			cout<<A<<endl;
		else 
			cout<<0<<endl;
		
		
	}
	return 0;
}