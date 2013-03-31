#include <iostream>
#include <cstdio>
//C. Oranges and Apples
using namespace std;
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define MAX 100000
int A[2*MAX+5];
int B[2*MAX+5];
int main(){
	int T,N,x,y;
	scanf("%d",&T);
	
	REP(i,0,T){
		scanf("%d",&N);
		int sa=0;
		int sb=0;
		A[0]=B[0]=0;
		REP(j,1,2*N){
			scanf("%d %d",&x,&y);
			A[j]+=x;
			B[j]+=y;
			sa+=x;
			sb+=y;
		}
		REP(j,N,2*N){
			A[j]+=x;
			B[j]+=y;
			sa+=x;
			sb+=y;
		}
		
		
	}
	
	return 0;
}