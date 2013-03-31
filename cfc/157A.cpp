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
int A[101][101],N;
int R[101];
int C[101];
int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&N);
	REP(i,0,N)REP(j,0,N)scanf("%d",&A[i][j]);
	int ans=0;
	
	REP(i,0,N){
		C[i]=0;
		R[i]=0;
	}
	REP(i,0,N){		
		REP(j,0,N){
			R[i]+=A[i][j];
			C[i]+=A[j][i];
		}
	}

	REP(i,0,N)
		REP(j,0,N){
			if(R[i]<C[j])
				ans++;
		}
	cout<<ans<<endl;
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	
}
