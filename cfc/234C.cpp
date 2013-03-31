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
#define INF 1<<30
#define MAX 100005
using namespace std;
int A[MAX],B[MAX],C[MAX],n;
void solve(){
	scanf("%d",&n);
	REP(i,0,n)scanf("%d",&A[i]);
	B[0]=A[0]>=0;
	C[n-1]=A[n-1]<=0;
	REP(i,1,n){
		B[i]=B[i-1]+(A[i]>=0);
		C[n-i-1]=C[n-i]+(A[n-i-1]<=0);
	}
	int ans=MAX;
	REP(i,0,n-1)
		ans=min(ans,C[i+1]+B[i]);	
	cout<<ans<<endl;
	
	
}
int main(){
	//freopen("E:/input.txt","r",stdin);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();	
	return 0;
}

