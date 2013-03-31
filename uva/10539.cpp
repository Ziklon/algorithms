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

set<long long>M;
long long Limite=1000000000000LL,N;
int L=1000000;
bool S[500005];

void go(long long m,int n){
	m=m*m;
	while(m<=Limite){
		M.insert(m);
		m*=n;
	}
}


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	fill(S,0);	
	for(int j=3;j*j<=L;j+=2)
		if(S[j>>1]==0)
			for(int k=j*j;k<=L;k+=(j*2))
				S[k>>1]=1;
	
	vector<long long> v(1,2);
	for(int i=3;i<=1000000;i+=2)
		if(S[i>>1]==0)
			v.push_back(i);
	REP(i,0,v.sz)go(v[i],v[i]);
	v.clear();	
	foreach(M,it)v.push_back(*it);
	
	long long P,Q,A,B,C;
	cin>>C;
	REP(i,0,C){
		cin>>A>>B;
		Q=upper_bound(all(v),B)-v.begin();
		P=lower_bound(all(v),A)-v.begin();
		cout<<(Q-P)<<endl;
	
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
