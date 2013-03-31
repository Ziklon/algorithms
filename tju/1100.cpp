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
int A[100],N;


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&N) && N){
		REP(i,0,N)scanf("%d",&A[i]);
		double P=0,Q=0;
		double peki=0;
		REP(i,0,N)REP(j,i+1,N){
			if(__gcd(A[i],A[j])==1)P++;
			Q++;
		}
		//cout<<P<<" "<<Q<<endl;
		if(P>0){
			peki=sqrt( (6*Q)/P);
			printf("%.6f\n",peki);			
		}
		else{
			printf("No estimate for this data set.\n");
		}
	
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
