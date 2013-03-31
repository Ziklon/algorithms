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
int T,A;

int solve(string n, int b){
	int peki=0;
	REP(i,0,n.sz){
		peki=(peki*b)+(n[i]-'0');
	}
	return peki;
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string tree;
	int b,c,p,q;
	while(cin>>s>>b>>t>>c){
		p=solve(s,b);
		q=solve(t,c);
		if(p==q)
			printf("=\n");
		else if(p<q)
			printf("<\n");
		else printf(">\n");
			
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
