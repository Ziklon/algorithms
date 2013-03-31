#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
#define MAX 1005
int P[MAX],i,j,rank[MAX],N,M,K,X,Y;


void init(int N){
	for(i=0;i<=N;i++){
		P[i]=i;
		rank[i]=1;
	}
}
int find(int n){
	while(P[n]!=n)
		n=P[n];
	return n;	
}

void join(int a, int b){
	int p=find(a);
	int q=find(b);
	if(rank[p]<rank[q]){
		P[p]=q;
		rank[q]+=rank[p];
	}else{
		P[q]=p;
		rank[p]+=rank[q];
	}
}
map<int,int>Mapa;

int main(){
	
	//freopen("D:/input.txt","r",stdin);
	while(scanf("%d %d %d\n",&N,&M,&K)==3){
		init(N);
		Mapa.clear();
		for(i=0;i<M;i++){
			scanf("%d %d\n",&X,&Y);
			join(X,Y);
		}
		Y=0;
		for(i=1;i<=N;i++)Mapa[find(i)]++;		
		for(i=1;i<=N;i++){
			
			if(Mapa[find(i)]-1>=K){
				if(Y==0)printf("%d",i);
				else printf(" %d",i);
				Y++;
			}
			
		}
		if(Y==0)printf("0\n");
		else printf("\n");				
	}
	return 0;
}