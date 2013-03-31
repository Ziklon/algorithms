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

int L=100,C,A,B;

bool S[55];
vector<int>P;


void go(int index,int suma, int n, vector<int> v){
	if(suma==0 && n==0){
		printf("1");
		REP(i,1,v.sz)printf(" %d",v[i]);
		printf("\n");
		return;
	}
	if(suma>0 &&  n>0){		
		for(int i=index;i<P.sz;i++){
			if(P[i]<=suma){
				vector<int> aux=v;	
				aux.push_back(P[i]);			
				go(i,suma-P[i],n-1,aux);
			}
		}
	}
	
	
}

int main(){
    clock_t start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	fill(S,0);	
	for(int j=3;j*j<=L;j+=2)
		if(S[j>>1]==0)
			for(int k=j*j;k<=L;k+=(j*2))
				S[k>>1]=1;
	
	P.push_back(2);
	for(int i=3;i<=L;i+=2)
		if(S[i>>1]==0)
			P.push_back(i);

	scanf("%d",&C);
	REP(i,0,C){
		scanf("%d %d",&A,&B);
		printf("Case %d:\n",i+1);
		go(0,A-2,B-2,vector<int>(2,1));
	}
	fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
