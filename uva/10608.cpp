#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define sz size()

using namespace std;
int P[30005];
int V[30005];
 void make(int n){
	REP(i,0,n+1){
		P[i]=i;
		V[i]=0;
	}
 }
 
 int FIND(int n){
	if(P[n]==n)return n;
	return P[n]=FIND(P[n]);
 }
 void UNION(int a, int b){
	P[FIND(a)]=FIND(b);	
 }
int main(){
	//freopen("in.txt","r",stdin);
	int T,N,M,x,y;
	scanf("%d",&T);
	REP(i,0,T){
		scanf("%d %d",&N,&M);
		make(N);
		REP(j,0,M){
			scanf("%d %d",&x,&y);
			UNION(x,y);
		}
		int peki=0;
		REP(j,1,N+1)
			V[FIND(j)]++;
		REP(j,1,N+1)peki=max(peki,V[j]);
		printf("%d\n",peki);
		
	}
	
	
	return 0;
}