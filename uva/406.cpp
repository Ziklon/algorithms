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
int N,C,T;
bool S[1005];
int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	vector<int> P;
	fill(S,0);
	for(int i=2;i*i<=1005;i++)
		if(S[i]==0){
			for(int j=i*i;j<1005;j+=i)
				S[j]=1;
		}
	REP(j,1,1001)
		if(S[j]==0)
			P.push_back(j);
	
	while(scanf("%d %d",&N,&C)==2){
		
		T++;
		int index=upper_bound(all(P),N)-P.begin();
		int req=C*2;
		if(index&1)req--;
		
		//cout<<index<<" "<<cn<<" "<<req<<endl;
		printf("%d %d:",N,C);
		if(req>=index){
			REP(i,0,index)
				printf(" %d",P[i]);
		}else{
			int m=(index-req)/2;
			REP(i,0,req){
				printf(" %d",P[m+i]);
			}
		}
			
		printf("\n");
		printf("\n");
		
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
