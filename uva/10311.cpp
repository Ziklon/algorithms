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
int L=100000000,X,a,Y;
bool S[50000005];


int main(){
    clock_t start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	fill(S,0);
	int N,index,i;
	for(int j=3;j*j<=L;j+=2)
		if(S[j>>1]==0)
			for(int k=j*j;k<=L;k+=(j*2))
				S[k>>1]=1;
	
	vector<int> v(1,2);
	for(int j=3;j<=L;j+=2)if(S[j>>1]==0)v.push_back(j);
	int P,Q,R;
	while(scanf("%d",&N)!=EOF){
		index=lower_bound(all(v),N)-v.begin();
		R=-1;
		for(i=index/2;i<=v.sz;i++){
			P=N-v[i];
			if(P<0)break;
			if(binary_search(all(v),P)){
				R=P;
				break;
			}
		}
		if(R==-1)printf("%d is not the sum of two primes!\n",N);
		else printf("%d is the sum of %d and %d.\n",N,N-R,R);
	}
	
	
	fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
