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
int T,N,X,a,b;
long long num;

int main(){
    //clock_t start = clock();
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	vector<int> v;
	for(int i=1;i*i<=1000000000;i++){
		v.push_back(i*i);
	}
	REP(i,0,T){
		scanf("%d",&N);
		printf("Case %d:",(i+1));
		vector<int> peki;
		REP(j,0,v.sz){
			X=N-v[j];
			if(X>N || X<1)break;
			b=sqrt(v[j]);
			if(X%b==0){
				peki.push_back(X);
				//printf(" %d",X);
			}
		}
		reverse(all(peki));
		REP(j,0,peki.sz)printf(" %d",peki[j]);
		printf("\n");
		
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
