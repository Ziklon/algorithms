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
long long N,M,i;


void solve(){
	cin>>N;
	int cnt=0;
	set<long long> S;
	for(i=1;i*i<=N;i++){
		if(N%i==0){
			S.insert(i);
			S.insert(N/i);
		}	
	}
	long long mm=N;
	int A[10]={};
	while(mm>0){
		A[mm%10]=1;
		mm/=10;
	}
	foreach(S,it){
		mm=*it;
		while(mm>0){
			if(A[mm%10]==1){
				cnt++;
				break;
			}
			mm/=10;
		}
		
	}
	cout<<cnt<<endl;
	
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

