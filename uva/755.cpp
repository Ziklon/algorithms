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
#define oo 1<<30
using namespace std;
char getDigit(char c){
  if(c>='A' && c<='C')return '2';
  if(c>='D' && c<='F')return '3';
  if(c>='G' && c<='I')return '4';
  if(c>='J' && c<='L')return '5';
  if(c>='M' && c<='O')return '6';
  if(c>='P' && c<='S')return '7';
  if(c>='T' && c<='V')return '8';
  if(c>='W' && c<='Y')return '9';
}
int t,n,k;
string line,sol;
int toint(string s){
	int ans=0;
	REP(i,0,s.sz)ans=ans*10+(s[i]-'0');
	return ans;
}
void solve(){
	scanf("%d\n",&n);
	REP(i,0,n){
		if(i)printf("\n");
		scanf("%d\n",&t);
		map<int,int>M;
		REP(j,0,t){
			getline(cin,line);
			sol="";
			REP(k,0,line.sz){
				if(line[k]!='-')
					sol+=(isdigit(line[k]))?line[k]:getDigit(line[k]);
			}			
			//sol=sol.substr(0,3)+"-"+sol.substr(3);
			M[toint(sol)]++;
		}
		bool ok=0;
		foreach(M,it)
			if(it->second>1){
				printf("%03d-%04d %d\n",it->first/10000,it->first%10000,it->second);
				ok=1;
			}
		if(!ok)printf("No duplicates.\n");
		
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

