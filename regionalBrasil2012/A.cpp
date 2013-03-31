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
int N,L,C,ans,c,M,l;
char buff[124];
void solve(){
	while(scanf("%d %d %d\n",&N,&L,&C)==3){
		ans=0;
		c=-1;
		l=1;
		REP(i,0,N){
			scanf("%s",buff);
			M=strlen(buff);
			//cout<<M<<" ";
			if((c+1+M)>C){
				l++;
				c=M;
			}
			else c=c+1+M;
					
			
		}
		ans=(l+L-1)/L;
		printf("%d\n",ans);
		
	
	}
	
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

