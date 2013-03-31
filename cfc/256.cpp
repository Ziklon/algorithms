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
#define INF 1<<30
#define MAX 40000
using namespace std;
int n,r,s;

long long P[MAX];


int toi(string s){
	int ans=0;
	REP(i,0,s.sz)ans=ans*10+(s[i]-'0');
	return ans;
}
string complete(string s, int n){
	while(s.sz<n)s="0"+s;
	return s;
}
string tos(int n){
	string ans="";
	while(n){
		ans=string(1,'0'+n%10)+ans;
		n/=10;
	}
	return ans;
}
void solve(){
	
	REP(i,0,MAX)P[i]=1LL*i*i;		
	while(scanf("%d",&n)==1){
		r=pow(10,n);
		REP(j,0,MAX){
			if(P[j]<r){
				string aux=complete(tos(P[j]),n);
				int a=toi(aux.substr(0,n/2));
				int b=toi(aux.substr(n/2,n/2));	
				if(P[a+b]==P[j]){
					if(n==2)printf("%02lld\n",P[j]);
					if(n==4)printf("%04lld\n",P[j]);
					if(n==6)printf("%06lld\n",P[j]);
					if(n==8)printf("%08lld\n",P[j]);
				}
			}else break;
		}
		
	}
	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}


