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

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string a,b;
	while(cin>>a>>b){
	int A[10][2];
	A[4][0]=A[7][0]=A[4][1]=A[7][1]=0;
	int dif=0;
	int n=a.sz;
	REP(i,0,a.sz){
		if(a[i]==b[i])continue;
		A[a[i]-'0'][0]++;
		A[b[i]-'0'][1]++;
		dif++;
	}
	int common=min(min(A[4][0],min(A[7][1],A[7][1])),A[4][1]);
	int ans=0;
	for(int i=0;i<common && dif>1 ;i++){
		dif-=2;
		ans++;
	}
	ans+=dif;
	cout<<ans<<endl;
	
	}
	return 0;
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	
}
