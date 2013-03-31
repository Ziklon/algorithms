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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<20
using namespace std;
string cad;
int n,a,b,c;

int A[3];
int B[3];

void solve(){
	cin>>n>>a>>b;
	cin>>cad;
	c=n-(a+b);
	if(c<0){
		puts("-1");
		return;
	}
	int C[]={a,b,c};
	fill(A,0);
	for(int i=0;i<cad.sz;i++)
		A[cad[i]-'0']++;
	int ch=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			if(i==j)continue;
			if(A[i]>C[i] && A[j]<C[j]){
				int pas=min(A[i]-C[i],C[j]-A[j]);
				int voy=0;
				ch+=pas;
				for(int k=0;k<cad.sz;k++)if(cad[k]==('0'+i) && voy<pas){
					cad[k]='0'+j;
					voy++;
				}
					
			}	
		}
	cout<<ch<<endl;
	cout<<cad<<endl;
	
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

