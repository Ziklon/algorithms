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
int N;
char A[1<<20];
int P[1<<20];
int D[1<<20];
int M[1<<20];
int R[1<<20];
struct nodo{
	int index, P,intev;
	nodo(int a, int b, int c){
		index=a;
		P=b;
		intev=c;
	}
	bool operator < (const nodo &o)const{
		return P>o.P;
	}
};
void solve(){
	cin>>N;
	queue<pair<int,int> > Q;
	
	for(int i=0;i<=N;i++){
		D[i]=INF;
		R[i]=0;
	}
	
	vector<int>ans;
	for(int i=2;i<=N;i++)
		cin>>A[i]>>P[i];
	
	vector<nodo> tmp;
	int ind=0;
	int ha=0;
	for(ha=N-1;ha>=2;ha--)if(A[ha]=='p')break;
	
	
	for(int i=2;i<=ha;i++){	
		if(A[i]=='p'){
			M[ind]=P[i];
			ind++;
		}else{
			tmp.push_back(nodo(i,P[i],ind));
		}
	}
	sort(all(tmp));
	

	for(int i=ind-1;i>=0;i--){
		D[i]=min(M[i]-1,D[i]);
	}

	int killeds=0;
	long long golds=0;
	for(int i=0;i<tmp.sz;i++){
		nodo cur=tmp[i];
		if(R[cur.intev]<D[cur.intev]){
			R[cur.intev]++;
			ans.push_back(cur.index);
			killeds++;
			golds+=cur.P;
		}	
	}	
	for(int i=N-1;i>=2;i--){
		if(A[i]=='p')break;
		ans.push_back(i);
		killeds++;
		golds+=P[i];	
	}
	if(P[N]>killeds){
		puts("-1");
	}else{
		cout<<golds<<endl;
		cout<<killeds<<endl;
		sort(all(ans));
		for(int i=0;i<ans.sz;i++){
			if(i)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
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

