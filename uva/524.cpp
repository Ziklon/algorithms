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
int n;
vector<int>P;
bool isPrime(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
bool into(vector<int>& v, int n){
	REP(i,0,v.sz)if(v[i]==n)return 1;
	return 0;
}

void go(vector<int> v){
	if(v.sz==n && binary_search(all(P),1+v[n-1])){
		printf("1");
		REP(i,1,v.sz)printf(" %d",v[i]);
		printf("\n");
		return;		
	}
	
	for(int i=2;i<=n;i++){		
		if(!into(v,i) && binary_search(all(P),i+v[v.sz-1])){
			vector<int> aux(all(v));
			aux.push_back(i);
			go(aux);
		}
	}
	
}


int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	REP(i,2,32)if(isPrime(i))P.push_back(i);
	int Tc=1;
	while(cin>>n){
		if(Tc>1)printf("\n");
		printf("Case %d:\n",Tc++);		
		go(vector<int>(1,1));
		
	}
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
