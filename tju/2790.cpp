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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int A[102];
bool vis[2000005];
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int C,N;
   cin>>C>>N;
   REP(i,0,C)
   	cin>>A[i];
	
	sort(A,A+C);
	fill(vis,0);
	reverse(A,A+C);
	vector<int> vc;
	REP(i,0,C){
		bool ok=1;
		REP(j,i+1,C){
			if(__gcd(A[i],A[j])==A[j])
				ok=0;
		}
		if(ok)vc.push_back(A[i]);
	}
	REP(i,0,vc.sz){
		for(int j=vc[i];j<=N;j+=vc[i])
			vis[j]=1;
	}
	int ans=0;
	REP(i,1,N+1)
		ans+=vis[i];
	printf("%d\n",ans);
   //system("pause");
   return 0;
}
