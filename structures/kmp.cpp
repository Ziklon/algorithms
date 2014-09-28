#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
#define MAX_L 1000000

int F[MAX_L];

void prefixFunction(string P){
	int n=P.size(),k=0;
	F[0]=0;
	for(int i=1;i<n;i++){
		while(k>0 && P[k]!=P[i])k=F[k-1];
		if(P[k]==P[i])++k;
		F[i]=k;		
	}
}
int KMP(string P, string T){
	int n=P.size(),L=T.size(),k=0,ans=0;
	for(int i=0;i<L;i++){
		while(k>0 && P[k]!=T[i])k=F[k-1];
		if(P[k]==T[i])++k;		
		if(k==n){
			ans++;
			k=F[k-1];
		}		
	}
	return ans;	
}

int main(){
	string T="barfoobarfoobarfoobarfoobarfoo";
	string P="foobarfoo";
	prefixFunction(P);
	cout<<KMP(P,T)<<endl;					
	return 0;
}
