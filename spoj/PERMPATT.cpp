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
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define sz size()
using namespace std;
pair<int,int>P[100009];
int N,M,x;
int I[4];
bool ok=0,peki;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&N);
	REP(k,0,N){
		scanf("%d",&M);
		REP(i,0,M){
			scanf("%d",&x);
			P[i]=make_pair(x,i);
		}
		sort(P,P+M);
		peki=0;
		for(int i=0;(i+4)<=M && !peki;i++){
			
			REP(j,0,4)I[j]=P[i+j].second;
			
			REP(j,0,4)cout<<I[j]<<" ";
			cout<<endl;
			if(I[0]<I[2] && I[1]<I[3] && I[1]>I[2])peki=1;
		}
		if(peki)printf("yes\n");
		else printf("no\n");
	}
	return 0;
	
}