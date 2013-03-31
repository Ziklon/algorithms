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
int A[101],N;

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&N);
	REP(i,0,N)scanf("%d",&A[i]);
	
	sort(A,A+N);
	double ans=0;
	for(int i=N-1;i>=0;i-=2){
		ans+=A[i]*A[i];
		if(i>=1)
			ans-=A[i-1]*A[i-1];
	}
	ans*=M_PI;
	printf("%.15f\n",ans);
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	
}
