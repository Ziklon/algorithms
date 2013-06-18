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

bool S[1000005];
int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	fill(S,0);
	for(int i=2;i*i<=1000000;i++)
		if(!S[i])
			for(int j=i*i;j<=1000000;j+=i)
				S[j]=1;
	vector<int> P;
	REP(i,2,1000000)if(!S[i])P.push_back(i);
	int T,x,y,index,U,V;
	scanf("%d",&T);
	REP(i,0,T){
		scanf("%d %d",&x,&y);
		index=lower_bound(all(P),x)-P.begin();
		map<int,int>M;
		for(int j=index+1;j<P.sz;j++){
			if(P[j]>y)break;
			M[P[j]-P[j-1]]++;
		}
		V=-1;
		U=0;
		foreach(M,it){
			if(it->second>U){
				U=it->second;
				V=it->first;
			}else if(it->second==U){
				V=-1;
			}
		}
		if(V!=-1)printf("The jumping champion is %d\n",V);
		else printf("No jumping champion\n");
		
	}	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
