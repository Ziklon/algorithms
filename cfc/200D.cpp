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
using namespace std;
int n,m,k,aux;
string removeSpace(string s){
	string ans="";
	REP(i,0,s.sz)if(s[i]!=' ')ans+=s[i];
	return ans;
}
string trim(string s){
	string ans="";
	int x=0;
	int y=s.sz-1;
	while(s[x]==' ')x++;
	while(s[y]==' ')y--;
	for(;x<=y;x++)ans+=s[x];
	return ans;	
}
vector<string> vp,vv,vc;
string cad;
void solve(){
	scanf("%d\n",&n);
	REP(i,0,n){
		getline(cin,cad);
		aux=cad.find("void");
		cad=cad.substr(aux+4);
		vp.push_back(removeSpace(cad));
	}
	scanf("%d\n",&m);
	REP(i,0,m){
		getline(cin,cad);
		vv.push_back(trim(cad));
	}
	scanf("%d\n",&k);
	sort(all(vp));
	sort(all(vv));
	
	REP(i,0,m){
		getline(cin,cad);
		
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

