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
#define oo 1<<30
using namespace std;
string A[1500],B[1500];
int V[1500];
void solve(){
	int N,D;
	scanf("%d %d\n",&N,&D);
	REP(i,0,N){
		cin>>A[i]>>B[i]>>V[i];	
	}
	set<string> S;
	REP(i,0,N)
		REP(j,i+1,N){
			if(A[i]==B[j] && B[i]==A[j] && V[i]!=V[j]&&(V[j]-V[i])<=D){
				S.insert(min(A[i],B[i])+" "+max(A[i],B[i]));			
			}
		}
	cout<<S.sz<<endl;
	foreach(S,it)
		cout<<*it<<endl;
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

