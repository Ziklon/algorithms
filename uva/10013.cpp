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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
int A[1<<20],B[1<<20],C[1<<20];
int N,M,carry;
int main(){	
	scanf("%d",&N);
	for(int t=0;t<N;t++){
		if(t)printf("\n");
		scanf("%d",&M);
		for(int i=0;i<M;i++)
			scanf("%d %d",&A[i],&B[i]);
		carry=0;
		for(int i=M-1;i>=0;i--){
			C[i]=(A[i]+B[i]+carry);
			if(C[i]>=10){
				C[i]-=10;
				carry=1;	
			}else
				carry=0;
		}
		for(int i=0;i<M;i++)printf("%d",C[i]);
		printf("\n");		
	}	
	return 0;
}

