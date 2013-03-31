/*
ID: winftc2
PROG: milk3
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int A[3];
int vis[21][21][21];

set<int> S;


int fal(int i, int j){
	int C[3]={};
	C[i]=C[j]=1;
	REP(i,0,3)if(!C[i])return i;
	return 0;
}

void go(int a, int b, int c){
	
	if(a==0){
		S.insert(c);
	}
	if(vis[a][b][c])return;
	vis[a][b][c]=1;
	int B[3]={a,b,c};
	REP(i,0,3){
		if(B[i]>0){
			REP(j,0,3){
				if(i==j)continue;
				int k1=A[j]-B[j];
				int r1=min(k1,B[i]);
				int C[3]={};
				int k=fal(i,j);
				//cout<<i<<" "<<j<<" "<<k<<endl;
				C[k]=B[k];
				C[i]=B[i]-r1;
				C[j]=B[j]+r1;
				go(C[0],C[1],C[2]);			
			}		
		}	
	}
	
	
	
}


int main(){
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    REP(i,0,3)cin>>A[i];
	memset(vis,0,sizeof vis);
	go(0,0,A[2]);
	vector<int> peki;
	foreach(S,it){
		peki.push_back(*it);
	}
	printf("%d",peki[0]);
	REP(i,1,peki.sz)printf(" %d",peki[i]);
	printf("\n");
	
    return 0;
}
