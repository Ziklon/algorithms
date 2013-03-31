#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define MAX_L 5000000

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
vector<int> KMP(string P, string T){
	int n=P.size(),L=T.size(),k=0;
	vector<int> ans;
	for(int i=0;i<L;i++){
		while(k>0 && P[k]!=T[i])k=F[k-1];
		if(P[k]==T[i])++k;		
		if(k==n){
			ans.push_back(i-n+1);
			k=F[k-1];
		}		
	}
	return ans;	
}
int n;
string P,T;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>P>>T){
		prefixFunction(P);
		vector<int> v=KMP(P,T);
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<endl;		
		if(v.size()==0)cout<<endl;	
	}					
	return 0;
}
